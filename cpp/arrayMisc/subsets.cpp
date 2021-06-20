/*

    LEETCODE# 78

    Given an integer array nums of unique elements, return all possible subsets (the power set).

    The solution set must not contain duplicate subsets. Return the solution in any order.

 

    Example 1:
    Input: nums = [1,2,3]
    Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

    Example 2:
    Input: nums = [0]
    Output: [[],[0]]
 

    Constraints:
        1 <= nums.length <= 10
        -10 <= nums[i] <= 10
        All the numbers of nums are unique.


*/

#include <iostream>
#include <vector>

using namespace std;

void helper(int index, vector<int> nums, vector<int> subset, vector<vector<int>> &result) {
    
    result.push_back(subset);
    
    for (int i = index; i < nums.size(); i++) {
        subset.push_back(nums[i]);    // add num to perm
        helper(i+1, nums, subset, result);
        subset.pop_back();            // unwind for next i
    }
}    

vector<vector<int>> subsets(vector<int> nums) {
    vector<vector<int>> result{};
    vector<int> subset{};
    
    if (nums.size() == 0) {
        result.push_back(nums);
        return result;
    }
    
    helper(0, nums, subset, result);
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

    vector<vector<int>> result = subsets({1,2,3});
    printSubsets("[1,2,3] --> ", result);

    result = subsets({0});
    printSubsets("[0] --> ", result);

    return 0;
}


