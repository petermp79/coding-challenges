/*
    Merge overlapped intervals:

    [[1,4], [0, 3], [2, 6], [8, 14], [12, 15]] => [[0, 6], [8, 15]] 
*/ 

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> mergeOverlapIntervals(vector<vector<int>> intervals) {
    vector<vector<int>> result;

    sort(intervals.begin(), intervals.end());

    int start = intervals[0][0];
    int end = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++) { //auto it : intervals) {
        if (intervals[i][0] > end) {
            // not overlap
            result.push_back({start, end});
            start = intervals[i][0];
            end = intervals[i][1];
        }
        else {
            // overlap
            end = max(end, intervals[i][1]);
        }
    }
    // save last interval
    result.push_back({start, end});

    return result; 
}


int main() {
    vector<vector<int>> intervals = { {1, 4}, {0, 3}, {2, 6}, {8, 14}, {12, 15} };

    cout << "Intervals: ";
    for (auto it : intervals) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }  
    cout << endl;

    vector<vector<int>> result = mergeOverlapIntervals(intervals);

    cout << "Result: ";
    for (auto it : result) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }  
    cout << endl;
}


