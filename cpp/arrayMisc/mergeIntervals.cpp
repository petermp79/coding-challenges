/*

    LEETCODE# 56

    Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
    and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

    Example 1:

    Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
    Output: [[1,6],[8,10],[15,18]]
    Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

    Example 2:

    Input: intervals = [[1,4],[4,5]]
    Output: [[1,5]]
    Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

    Constraints:
        1 <= intervals.length <= 104
        intervals[i].length == 2
        0 <= starti <= endi <= 104
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> result;

    sort(intervals.begin(), intervals.end());
    if (intervals.size() == 1) {
        return intervals;
    }
    int start = intervals[0][0];
    int end = intervals[0][1];
    for (auto i : intervals) {
        if (i[0] > end) {
            // Overlap 
            result.push_back({start, end});
            start = i[0];
            end = i[1];
        }
        else {
            end = max(end, i[1]);
        }
    }
    result.push_back({start, end});
    return result;
}

void printSubsets(string heading, vector<vector<int>> subsets) {

    cout << heading;
    for (auto subset : subsets) {
        cout << "[";
        for (auto x : subset) {
            cout << x << ",";
        }
        cout << "], ";
    }
    cout << endl;
}


int main() {

    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> result = merge(intervals);
    printSubsets("[[1,3],[2,6],[8,10],[15,18]] --> ", result);

    intervals = {{1,4},{4,5}};
    result = merge(intervals);
    printSubsets("[[1,4],[4,5]] --> ", result);

}




