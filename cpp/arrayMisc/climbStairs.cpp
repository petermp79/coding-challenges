/*
    LEETCODE #70

    You are climbing a staircase. It takes n steps to reach the top.
    Each time you can either climb a number of possible steps. 
    In how many distinct ways can you climb to the top?

    Example 1:

    Input: n = 2
    Output: 2

    Explanation: There are two ways to climb to the top.
    1. 1 step + 1 step
    2. 2 steps

    Example 2:

    Input: n = 3
    Output: 3

    Explanation: There are three ways to climb to the top.
    1. 1 step + 1 step + 1 step
    2. 1 step + 2 steps
    3. 2 steps + 1 step

    // TC O(n * steps) SC O(n)
    // Algorithm:
    // 1. Calculate #ways based on #stairs and #possible steps and save in
    //    an array (dynamic programming)
    // 2. As #stairs progresses up to n, sum up #ways of previous #stairs
    //

 */

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int waysToClimb(int n, vector<int> possibleSteps){
    int *nWays = new int[n+1]{};    // array to keep track of #ways based on #ofstairs
    nWays[0] = 1;                   // no stair, no climb counts as 1 way
    
    for (int i = 1; i < n+1; i++) { // For each #stairs
        // Calc nbWays based on possible steps
        int nbWays = 0;
        for (auto steps : possibleSteps) {
            if (i >= steps) { // is there more stairs than steps?
                nbWays += nWays[i-steps];
            }
        }
        nWays[i] = nbWays;  // #ways for i #stairs
    }
    return nWays[n];
}

// Function to get multiple input on the same line
// Optionally, output input data for visual inspection
//
vector<int> getMultiInput(string msg, bool output) {
    vector<int> inputs{}; 
    std::string line;
    int data = 0;

    cout << msg;

    cin >> data;
    inputs.push_back(data);

    // get the rest input data
    std::getline(std::cin, line);
    std::istringstream input(line);
    while (input >> data) {
        inputs.push_back(data);
    }

    if (output) {
        for (auto data : inputs) {
            cout << data << " ";
        }
        cout << endl;
    }
    return inputs;
}

int main() {

    while (1) {
        int nStairs = 0;
        cout << "Enter the number of stairs (^C to quit): ";
        cin >> nStairs;
        vector<int> possibleSteps = getMultiInput("Enter the possible steps: ", true);

        cout << "Number of ways: " << waysToClimb(nStairs, possibleSteps) << endl;
    }
}
