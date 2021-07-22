
let fs = require("fs");
let lineReader = require('line-reader'); 

const headingStr = [ "North", "East", "South", "West" ];

const direction = {
    NORTH: 0,
    EAST:  1,
    SOUTH: 2,
    WEST:  3
};

const turnTable = [ 
        [ direction.NORTH, direction.EAST, direction.SOUTH, direction.WEST ],
        [ direction.EAST, direction.SOUTH, direction.WEST, direction.NORTH ],
        [ direction.SOUTH, direction.WEST, direction.NORTH, direction.EAST ],
        [ direction.WEST, direction.NORTH, direction.EAST, direction.SOUTH ],
    ];

class ShipPosition {

    constructor(heading) {
        this.heading = heading;             // initial ship heading
        this.distance = [ 0, 0, 0, 0 ];     // initial distance travel in 4 directions
    }

    // get current heading direction
    getHeading() {
        return this.heading;
    }

    getHeadingStr() {
        return headingStr[this.heading];
    }

    // calculate manhattan distrance traveled
    mDistance() {
        return Math.abs(this.distance[direction.NORTH] - this.distance[direction.SOUTH]) + 
                Math.abs(this.distance[direction.EAST] - this.distance[direction.WEST]);
    }

    // go a distance in the given direction
    go(dir, distance) {
       this.distance[dir] += distance; 
    }

    // turn left some degree, determine new heading
    turnLeft(degree) {
        if ((degree % 90) || (degree > 360)) {
            // take only multiple of 90 up to 360 inclusive
            return;
        }

        let i = (4 - (degree / 90));
        this.heading = turnTable[this.heading][i];  
    }

    // turn right some degree, determine new heading
    turnRight(degree) {
        if ((degree % 90) || (degree > 360)) {
            // take only multiple of 90 up to 360 inclusive
            return;
        }

        let i = degree / 90;
        this.heading = turnTable[this.heading][i];  
    }
};

function navigate(sp, cmd) {
    // separate command string into letter and digits, e.g. 'R90' --> 'R' and '90'
    let x = cmd.match(/[^\d]+|\d+/g);
    //console.log(x);
    if (x) {
        switch(x[0]) {
        case 'F':
            sp.go(sp.getHeading(), Number(x[1]));
            break;
        case 'N':
            sp.go(direction.NORTH, Number(x[1]));
            break;
        case 'E':
            sp.go(direction.EAST, Number(x[1]));
            break;
        case 'S':
            sp.go(direction.SOUTH, Number(x[1]));
            break;
        case 'W':
            sp.go(direction.WEST, Number(x[1]));
            break;
        case 'L':
            sp.turnLeft(Number(x[1]));
            break;
        case 'R':
            sp.turnRight(Number(x[1]));
            break;
        }
    }
}


// read data file, return promise
//
function readFile(fileName) {
    return new Promise((resolve, reject) => {
        fs.readFile(fileName, (err, data) => {
            if (err) reject(err);

            resolve(data);
        });
    });
}

// process cmd list, return promise
//
function processCmd(sp, data) {
    return new Promise((resolve, reject) => {
        // Convert buffer to string and then split line-by-line
        let cmdList = data.toString().split('\n');
        //console.log(cmdList);

        for (let i = 0; i < cmdList.length; i++) {
            // Split data int cmd and value
            navigate(sp, cmdList[i]);
        }
        resolve('Done');
    })
}


// node (0) ship.js (1) filename (2)
if (!process.argv[2]) {
    console.error("Please specify a data file!!!");
    process.exit(1);
}

let fileName = process.argv[2];

console.log(`Filename: ${fileName}`);


/* Method 1 - Synchronous operation --> console.log
 */

function method1() {
    let sp = new ShipPosition(direction.EAST);

    fs.readFile(fileName, (err, data) => {
        //console.log(`file data: ${data}`);
    
        // Convert data buffer to string and then split buffer into command lines
        let cmdList = data.toString().split('\n');
        //console.log(cmdList);
    
        // process commands
        for (let i = 0; i < cmdList.length; i++) {
            // Split data int cmd and value
            let cmd = cmdList[i];
            navigate(sp, cmd);
        }
        console.log("Method1. Done - Manhattan distance: " + sp.mDistance(), " + Heading: " + headingStr[sp.getHeading()]);
    });
}

/* Method 2 - Promise chaining using bulk readFile
 */

function method2() {
    let sp = new ShipPosition(direction.EAST);

    // let f = readFile;
    // f(fileName)

    readFile(fileName)
        .then(data => {
            //console.log(`file data: ${data}`);
            return processCmd(sp, data);
        })
        .then(message => {
            console.log("Method2. " + message + " - Manhattan distance: " + sp.mDistance(), " + Heading: " + headingStr[sp.getHeading()]);
        })
        .catch(err => {
            console.error(err);
        });
}

/* Method 3 - Promise chaining using line-by-line reader
 */

function method3() {
    let sp = new ShipPosition(direction.EAST);

    let pList = new Promise( (resolve, reject) => {
        lineReader.eachLine(fileName, function(cmd) {
            if (cmd[0] == 'Z')
                resolve('Done');

            navigate(sp, cmd);
        });

    }).then((resolve) => {
        console.log("Method3. " + resolve + " - Manhattan distance: " + sp.mDistance(), " + Heading: " + headingStr[sp.getHeading()]);
    }).catch((reject) => {
        // lineReader.eachLine() does not return err even if the file does not exist
        console.log(reject);
    });
}

/* Method 4 - Async/Await on sync operations
 */
function processCmdSync(sp, data) {
    // Convert buffer to string and then split line-by-line
    let cmdList = data.toString().split('\n');
    //console.log(cmdList);
    for (let i = 0; i < cmdList.length; i++) {
        // Split data int cmd and value
        navigate(sp, cmdList[i]);
    }
    return 'Done';
}

async function method4() {
    let sp = new ShipPosition(direction.EAST);

    try {
        const data = await fs.readFileSync(fileName);
        const result = await processCmdSync(sp, data);
        console.log("Method4. " + result + " - Manhattan distance: " + sp.mDistance(), " + Heading: " + headingStr[sp.getHeading()]);
    } catch (err) {
        console.log(err + " - Manhattan distance: " + sp.mDistance(), " + Heading: " + headingStr[sp.getHeading()]);
    }
}

// Test runner
//
async function runAllTests() {
    let result = await method1();
    result = await method2();
    result = await method3();
    result = await method4();
}


runAllTests();

