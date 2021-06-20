/*
  LEETCODE# 162

  Find peak element

  A peak element is an element that is strictly greater than its neighbors.

  Given an integer array nums, find a peak element, and return its index. If the array contains 
  multiple peaks, return the index to any of the peaks.

  You may imagine that nums[-1] = nums[n] = -∞.

  You must write an algorithm that runs in O(log n) time.

  Example 1:
  Input: nums = [1,2,3,1]
  Output: 2
  Explanation: 3 is a peak element and your function should return the index number 2.

  Example 2:
  Input: nums = [1,2,1,3,5,6,4]
  Output: 5
  Explanation: Your function can return either index number 1 where the peak element is 2, 
    or index number 5 where the peak element is 6.

*/

#include <iostream>
#include <vector>
using namespace std;

int findPeak(vector<int> arr){
    // your code here
    int prev = INT_MIN;
    int next;
    
    for (int i = 0; i < arr.size(); i++) {
        if (i == arr.size()-1) 
            next = INT_MIN;
        else
            next = arr[i+1];
        
        if (arr[i] >= prev && arr[i] >= next) {
            return i;
        }
        prev = arr[i];
    }
    return -1;
}

int main() {

    cout << "{6} --> " << findPeak({6}) << endl;
    cout << "{-1} --> " << findPeak({-1}) << endl;

    cout << "{-1, 2, 3} --> " << findPeak({-1, 2, 3 }) << endl;
    cout << "{1, 2, 3, 4} --> " << findPeak({1, 2, 3, 4}) << endl;
    cout << "{1, 2, 3, 2, 4} --> " << findPeak({1, 2, 3, 2, 4}) << endl;

    return 0;
}

