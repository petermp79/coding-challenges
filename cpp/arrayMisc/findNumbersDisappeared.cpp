/*

    LEETCODE# 448

    Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers 
    in the range [1, n] that do not appear in nums.

 

    Example 1:

    Input: nums = [4,3,2,7,8,2,3,1]
    Output: [5,6]

    Example 2:

    Input: nums = [1,1]
    Output: [2]
 

    Constraints:
    
    n == nums.length
    1 <= n <= 10^5
    1 <= nums[i] <= n
 

    Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not 
    count as extra space.


*/

#include <iostream>
#include <vector>

using namespace std;

// Fact: dup numbers are where missing numbers are
// TC O(N)
//
vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> result{};
    
    // 1. Convert all numbers in nums and negate them
    for (int i = 0; i < nums.size(); i++) {
        int n = abs(nums[i])-1;
        //cout << n << "->";
        if (nums[n] > 0)
            nums[n] = -nums[n];
        //cout << nums[n] << ",";
    }
    //cout << endl;
    
    // 2. Scan from 1-n and if nums[i] is positive, it is dup number
    //    record its index+1 as missing number
    //
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0)
            result.push_back(i+1);
    }
    return result;
}

// Print values in an array
//
void printArray(string heading, vector<int> array, int len=0) {
    if (len == 0)
        len = array.size();

    cout << heading << "[";
    for (int i = 0; i < len; i++) {
        cout << array[i] << ",";
    }
    cout << "]" << endl;
}

int main() {
    vector<int> result{};
    vector<int> nums = {4,3,2,7,8,2,3,1 };
    
    printArray("Input: ", nums);
    result = findDisappearedNumbers(nums);
    printArray("Output: ", result);

    nums = {1,1};
    printArray("Input: ", nums);
    result = findDisappearedNumbers(nums);
    printArray("Output: ", result);

    return 0;
}


