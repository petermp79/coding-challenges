This directory contains C++ and Javascript solution to an interview questioned 
I had with a company.

In Javascript file, I demo different ways to handle file I/O: synchronous, promise
and async/await.

To compile C++ file on linux:

    g++ -std=c++11 ship.cpp -o ship

The file shipdata.[small|big] files contains commands to steer the ship.

To run, the test:


    ship shipdata.small (or big)
 
