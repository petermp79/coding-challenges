/*
    LEETCODE# 15

    Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, 
    and j != k, and nums[i] + nums[j] + nums[k] == 0.

    Notice that the solution set must not contain duplicate triplets.

    >> A variation of this problem is to return triplets of index instead of num values themselves.
       In this case, we need to keep track of original index of each number after sorting.

    Example 1:

    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]

    Example 2:

    Input: nums = []
    Output: []

    Example 3:

    Input: nums = [0]
    Output: []


    Constraints:
        0 <= nums.length <= 3000
        -105 <= nums[i] <= 105

*/

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

//
//  1/ Sort array
//  2/ For each number in array, use left and right pointers to look for number pairs that
//         number[i] + number[left] + number[right] = 0
//  3/ Then, save triplet to a set to avoid duplicates
//  4/ Return 2D vector as required 
//
vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> set;       // use set container to avoid duplicate triplet results
    
    // Sort the list of #
    sort(nums.begin(), nums.end());

    //for (int i = 0; i < nums.size(); i++) cout << nums[i] << " ";
    //cout << endl;
    
    // For every # in the list, use left and right pointer to scan thru the list
    // and find sum of # + left + right = target sum
    //
    for (int i = 0; i < nums.size(); i++) {
        int left = i+1;                     // left starts after current #
        int right = nums.size()-1;          // right starts at last #
        
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                set.insert({nums[i], nums[left], nums[right]});
                right--;            // continue to find other pairs
                left++;
            }
            else if (sum > 0) {
                right--;            // need a smaller #
            }
            else
                left++;             // need a bigger #
        } 
    }
    vector<vector<int>> result(set.begin(), set.end());  // convert back to vector
    return result;
}
//


int main()
{
    vector<int> nums = { -1, 0, 1, 2, -1, -4 };
    vector<vector<int>> result = threeSum(nums);

    cout << "[ ";
    for (int i = 0; i < result.size(); i++) {
        cout << "[ ";
        for (int j : result[i]) {
            cout << j << ' ';
        }
        cout << " ]";
    }
    cout << " ]" << endl;
}


