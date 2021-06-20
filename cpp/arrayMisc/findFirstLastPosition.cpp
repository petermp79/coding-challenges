/*

   Given an array of integers nums sorted in ascending order, find the starting and ending position of 
   a given target value.

   If target is not found in the array, return [-1, -1].

   You must write an algorithm with O(log n) runtime complexity.

   Example 1:

   Input: nums = [5,7,7,8,8,10], target = 8
   Output: [3,4]

   Example 2:

   Input: nums = [5,7,7,8,8,10], target = 6
   Output: [-1,-1]

   Example 3:

   Input: nums = [], target = 0
   Output: [-1,-1]

   Algorithm:

    1/ Use binary search to find target#
    2/ Scan left and right to locate first and last elem of the target

*/

#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> nums, int l, int h, int target) {
    if (l > h)
        return -1;
    
    int mid = (l + h) / 2;
    if (nums[mid] == target)
        return mid;
    
    if (nums[mid] > target)
        return binarySearch(nums, l, mid-1, target);
    else
        return binarySearch(nums, mid+1, h, target);
}

int main() {
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    
    cout << "Array: ";
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;
    cout << "Target: " << target << endl;

    int index = binarySearch(nums, 0, nums.size()-1, target);
    if (index == -1) { 
        cout << "Result: -1, -1" << endl;
        return 0;
    }
    
    // Find start pos in the left
    int start = index;
    while (start >= 0 && nums[start] == target) start--;
    
    // Find end pos in the right
    int end = index;
    while (end <= nums.size()-1 && nums[end] == target) end++;
    
    cout << "Result: " << start+1 << ", " <<  end-1 << endl;

    return 0;
}

