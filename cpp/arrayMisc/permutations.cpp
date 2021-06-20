/*
    LEETCODE# 46

    Given an array nums of distinct integers, return all the possible permutations. 
    You can return the answer in any order.

 

    Example 1:

    Input: nums = [1,2,3]
    Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

    Example 2:

    Input: nums = [0,1]
    Output: [[0,1],[1,0]]

    Example 3:

    Input: nums = [1]
    Output: [[1]]
 

    Constraints:

        1 <= nums.length <= 6
        -10 <= nums[i] <= 10
        All the integers of nums are unique.

*/

#include <iostream>
#include <vector>

using namespace std;

void helper(vector<int> nums, vector<bool> visited, vector<int> perm, vector<vector<int>> &result) {
    
    if (perm.size() == nums.size()) {
        result.push_back(perm);
        return;
    }
    
    for (int i = 0; i < nums.size(); i++) {
        // did we include this one in perm 
        if (visited[i]) {
            // yes, dont do it again
            continue;
        }
       
        visited[i] = true;
        perm.push_back(nums[i]);    // add num to perm
        helper(nums, visited, perm, result);
        perm.pop_back();            // unwind for next i
        visited[i] = false;
    }
}

vector<vector<int>> permute(vector<int> nums) {
    vector<vector<int>> result{};
    vector<int> perm{};
    vector<bool> visited(nums.size(), false);
    
    if (nums.size() == 1) {
        // Only 1 permutation possible for 1 number
        result.push_back(nums);
        return result;
    }
    helper(nums, visited, perm, result);
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
    vector<vector<int>> result = permute({1, 2, 3});
    printSubsets("[1, 2, 3] --> ", result);

    result = permute({0, 1});
    printSubsets("[0, 1] --> ", result);

    result = permute({1});
    printSubsets("[1] --> ", result);

    return 0;
}


