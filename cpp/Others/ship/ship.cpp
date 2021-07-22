/*

Part One
==================

You are on a ferry heading towards an island, but a storm has come in faster than anyone expected. The ferry needs to take evasive actions!

Unfortunately, the ship's navigation computer seems to be malfunctioning; rather than giving a route directly to safety, it produced extremely circuitous instructions. When the captain uses the PA system to ask if anyone can help, you quickly volunteer.

The navigation instructions (your puzzle input) consists of a sequence of single-character actions paired with integer input values. After staring at them for a few minutes, you work out what they probably mean:

Action N means to move north by the given value.
Action S means to move south by the given value.
Action E means to move east by the given value.
Action W means to move west by the given value.
Action L means to turn left the given number of degrees.
Action R means to turn right the given number of degrees.
Action F means to move forward by the given value in the direction the ship is currently facing.
The ship starts by facing east. Only the L and R actions change the direction the ship is facing. (That is, if the ship is facing east and the next instruction is N10, the ship would move north 10 units, but would still move east if the following action were F.)

For example:

F10
N3
F7
R90
F11
These instructions would be handled as follows:

F10 would move the ship 10 units east (because the ship starts by facing east) to east 10, north 0.
N3 would move the ship 3 units north to east 10, north 3.
F7 would move the ship another 7 units east (because the ship is still facing east) to east 17, north 3.
R90 would cause the ship to turn right by 90 degrees and face south; it remains at east 17, north 3.
F11 would move the ship 11 units south to east 17, south 8.
At the end of these instructions, the ship's Manhattan distance (sum of the absolute values of its east/west position and its north/south position) from its starting position is 17 + 8 = 25.

Figure out where the navigation instructions lead. What is the Manhattan distance between that location and the ship's starting position?

*/


#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

#define H_EAST  0
#define H_WEST  1
#define H_NORTH 2
#define H_SOUTH 3
#define H_MAX   4

// int turn[H_MAX][5] = { 
vector<vector<int>> turn {
    /*  R0      R90      R180    R270    R360 */
    { H_EAST, H_SOUTH, H_WEST, H_NORTH, H_EAST },   // heading East, right-turn table (0 - E, 90 - S, 180 - W, 270 - N, 360 - E)
    { H_WEST, H_NORTH, H_EAST, H_SOUTH, H_WEST },
    { H_NORTH, H_EAST, H_SOUTH, H_WEST, H_NORTH },
    { H_SOUTH, H_WEST, H_NORTH, H_EAST, H_SOUTH }
};

string headingString[4] = { "EAST", "WEST", "NORTH", "SOUTH" };
    
class Position {

private:
    int heading;
    array<int, H_MAX> distance;                   // to keep track of distance travel in each direction

public:
    Position(int direction) {
        for (int i = 0; i < distance.size(); i++)
            distance[i] = 0;
        heading = direction;    // initial heading
        return;
    }

    // go some distance in the given direction
    void go(int dir, int dist) {
        if (dir < H_MAX) {
            distance[dir] += dist;
        }
        return;
    }

    // turn left from current direction
    void  turnLeft(int degree) {
        if ((degree % 90) || (degree > 360)) {
            // take only multiple of 90 up to 360 inclusive
            cout << ">>> Invalid turn: " << degree << endl;
            return; 
        }
        // change direction
        int i = H_MAX - degree/90;
        heading = turn[heading][i];
    }     

    // turn right from current direction
    void turnRight(int degree) {
        if ((degree % 90) || (degree > 360)) {
            // take only multiple of 90 up to 360 inclusive
            cout << ">>> Invalid turn: " << degree << endl;
            return; 
        }
        // change direction
        heading = turn[heading][degree/90];
        return;
    }     

    // Get current heading direction
    int getHeading() {
        return heading;
    }

    // total manhattan distance
    int getMDistance() {
        int n = distance[H_NORTH];
        int s = distance[H_SOUTH];
        int e = distance[H_EAST];
        int w = distance[H_WEST];
        return abs(n - s) + abs(e - w);  
    
    }
};


int main(int argc, char **argv) {

    Position ship(H_EAST);
    ifstream testFile;
    string line;
    string input;

    // cout << "Enter test file name: ";
    // cin >> input;

    if (!argv[1]) {
        cout << ">>> Error: Specify test data file name." << endl;
        return -1;
    }
    input = argv[1]; 

    // open test data file
    testFile.open(input);

    cout << ">>> MDistance: " << ship.getMDistance() << ", current heading: " << headingString[ship.getHeading()] << endl;
    cout << endl;

    if (testFile.is_open()) {
        while ( getline (testFile, line) ) {
            //cout << line << endl;

            switch(line[0]) {
                case 'F':
                    ship.go(ship.getHeading(), atoi(&line[1]));
                    break;
                case 'N':
                    ship.go(H_NORTH, atoi(&line[1]));
                    break;
                case 'S':
                    ship.go(H_SOUTH, atoi(&line[1]));
                    break;
                case 'E':
                    ship.go(H_EAST, atoi(&line[1]));
                    break;
                case 'W':
                    ship.go(H_WEST, atoi(&line[1]));
                    break;
                case 'L':
                    ship.turnLeft(atoi(&line[1]));
                    break;
                case 'R':
                    ship.turnRight(atoi(&line[1]));
                    break;
            }

        }
        testFile.close();
        cout << ">>> MDistance: " << ship.getMDistance() << ", current heading: " << headingString[ship.getHeading()] << endl;
        cout << endl;
    }
    else {
        cout << "File open error: " << input << endl;
    }

    return 0;
}


