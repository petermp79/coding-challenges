/*
    LEETCODE# 53

    Given an integer array nums, find the contiguous subarray (containing at least one number) 
    which has the largest sum and return its sum.

    Example 1:

    Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
    Output: 6
    Explanation: [4,-1,2,1] has the largest sum = 6.

    Example 2:

    Input: nums = [1]
    Output: 1

    Example 3:

    Input: nums = [5,4,-1,7,8]
    Output: 23
 
    Constraints:
    
        1 <= nums.length <= 3 * 104
        -105 <= nums[i] <= 105

Solution:
    Use Kadane algorithm.
    TC O(n), SC O(1);

*/

#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int> nums) {
    if (nums.size() == 1)
        return nums[0];
    
    int gSum = INT_MIN;
    int lSum = 0;

    for (int i = 0; i < nums.size(); i++) {
        lSum = max(nums[i], nums[i]+lSum);
        gSum = max(gSum, lSum);
    };
    return gSum;
}

int main() {
    cout << "[-2,1,-3,4,-1,2,1,-5,4] --> " << maxSubArray({-2,1,-3,4,-1,2,1,-5,4}) << endl;
    cout << "[5,4,-1,7,8] --> " << maxSubArray({5,4,-1,7,8}) << endl;
    cout << "[1] --> " << maxSubArray({1}) << endl;

    return 0;
}
