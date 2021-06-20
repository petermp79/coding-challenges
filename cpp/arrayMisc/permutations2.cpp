/*
    LEETCODE# 47

    Given a collection of numbers, nums, that might contain duplicates, return all possible unique 
    permutations in any order.

 

    Example 1:

    Input: nums = [1,1,2]
    Output:
        [[1,1,2],
        [1,2,1],
        [2,1,1]]

    Example 2:

    Input: nums = [1,2,3]
    Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

    Constraints:

        1 <= nums.length <= 8
        -10 <= nums[i] <= 10
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
        // is this one in permute list? 
        if (visited[i])
            continue;               // yes, skip it.
        //
        // If cur num is dup of prev one, and the prev one is not visited, i.e.
        // not already in permute list => skip.
        //
        else if (i > 0 && (nums[i] == nums[i-1]) && !visited[i-1])
            continue;
        
        visited[i] = true;
        perm.push_back(nums[i]);    // add num to perm
        
        helper(nums, visited, perm, result);
        
        perm.pop_back();            // unwind for next i
        visited[i] = false;
    }
}

vector<vector<int>> permuteUnique(vector<int> nums) {
    vector<vector<int>> result{};
    vector<int> perm{};
    vector<bool> visited(nums.size(), false);
    
    if (nums.size() == 1) {
        result.push_back(nums);
        return result;
    }
    
    sort(nums.begin(), nums.end());
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
    vector<vector<int>> result = permuteUnique({1, 1, 2});
    printSubsets("[1, 1, 2] --> ", result);

    result = permuteUnique({1, 2, 3});
    printSubsets("[1, 2, 3] --> ", result);

    return 0;
}


