
/*

    LEETCODE# 33 

    There is an integer array nums sorted in ascending order (with distinct values).

    Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) 
    such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] 
    (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

    Given the array nums after the rotation and an integer target, return the index of target if it is in nums, 
    or -1 if it is not in nums.

    You must write an algorithm with O(log n) runtime complexity.
 

    Example 1:
    Input: nums = [4,5,6,7,0,1,2], target = 0
    Output: 4

    Example 2:
    Input: nums = [4,5,6,7,0,1,2], target = 3
    Output: -1

    Example 3:
    Input: nums = [1], target = 0
    Output: -1


    Algorithm:
    1) Find middle point mid = (l + h)/2
    2) If key is present at middle point, return mid.
    3) Else If arr[l..mid] is sorted
        a) If key to be searched lies in range from arr[l]
        to arr[mid], recur for arr[l..mid].
        b) Else recur for arr[mid+1..h]
    4) Else (arr[mid+1..h] must be sorted)
        a) If key to be searched lies in range from arr[mid+1]
        to arr[h], recur for arr[mid+1..h].
        b) Else recur for arr[l..mid] 
*/

#include <iostream>
#include <vector>

using namespace std;

int search2(vector<int> arr, int l, int h, int key)
{
    if (l > h)
        return -1;
 
    int mid = (l + h) / 2;
    if (arr[mid] == key)
        return mid;
 
    
    if (arr[l] <= arr[mid]) {   // is arr[l...mid] is sorted?
        /* Yes, key must be in this half or other half */
        
        if (key >= arr[l] && key <= arr[mid])       // is key in lower half?
            return search2(arr, l, mid - 1, key);   // Yes, find it
        
        /* No, find key lies in the higher half */
        return search2(arr, mid + 1, h, key);
    }
    else {
        /* No, ... then higher half must be sorted */
        if (key >= arr[mid] && key <= arr[h])
            return search2(arr, mid + 1, h, key);
 
        return search2(arr, l, mid - 1, key);
    }
}

int main() {
    vector<int> nums; 
    int target;
 
    nums = { 4,5,6,7,8,9,0,1,2 };
    target = 1;

    cout << "Array: ";
    for (int i : nums) cout << i << " ";
    cout << "\nTarget: " << target << endl;;
    cout << "Result: " << search2(nums, 0, nums.size()-1, target) << endl;
}


