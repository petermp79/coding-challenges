/*

    A peak element is an element that is strictly greater than its neighbors.

    Given an integer array nums, find a peak element, and return its index. If the array contains multiple 
    peaks, return the index to any of the peaks.

    You may imagine that nums[-1] = nums[n] = -∞.

 

    Example 1:
    
    Input: nums = [1,2,3,1]
    Output: 2
    Explanation: 3 is a peak element and your function should return the index number 2.

    Example 2:

    Input: nums = [1,2,1,3,5,6,4]
    Output: 5
    Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 
    where the peak element is 6.
 
*/

#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums) {
    int i;

    if (nums.size() == 1)
        return 0;           // itself is a peak
    
    // Scan thru list and check if nums[i-1] < nums[i] > nums[i+1] exists, return i
    // Edge cases: [2, 1]--> 2, [1, 2, 3] --> 3
    //
    // TC O(N) SC O(1) 4ms
    //
    for (i = 0; i < nums.size()-1; i++) {
        if (i == 0) {
            // Edge case - x is the left-most number
            if (nums[i] > nums[i+1])
                return i;
            else 
                continue;
        }
        else {
            // x is in the midst of numbers
            if (nums[i-1] < nums[i] && nums[i] > nums[i+1]) {
                return i;
            }
        }
    }
    // Edge case: x is the right most number
    return i;
/*
    // Observation: a greatest number is always a peak, it could be:
    //  - At the starting or ending edge
    //  - In the midst of numbers since it is the greatest number, its left and right
    //    neighbors must be less than it.
    // TC O(nlogn) SC O(n) - 4ms
    //
    // Sort array and Find the greatest number
    vector<int>vec(nums.begin(),nums.end());
    sort(vec.begin(),vec.end());
    int x=vec[vec.size()-1];
    vector<int>::iterator itr=find(nums.begin(),nums.end(),x);
    
    // Return its index in the original array
    return distance(nums.begin(), itr);
*/
    
}

int main() {
    vector<int> nums;
    int num;

    while (1) {
        cout << "Enter numbers separated by white space (0 to terminate): ";
        nums = {};
        while (cin >> num) { //enter any non-integer to end the loop!
            if (num == 0)
                break;
            cout << num << " ";
            nums.push_back(num);
        }
        if (nums.size() == 0)
            break;  // terminate loop

        cout << "\nPeak elem: " << nums[findPeakElement(nums)] << endl;
    }

}


