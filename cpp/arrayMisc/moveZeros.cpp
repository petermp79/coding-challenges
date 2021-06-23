/*

    LEETCODE# 283

    Given an integer array nums, move all 0's to the end of it while maintaining the relative order of 
    the non-zero elements.

    Note that you must do this in-place without making a copy of the array.

 

    Example 1:

    Input: nums = [0,1,0,3,12]
    Output: [1,3,12,0,0]
    Example 2:

    Input: nums = [0]
    Output: [0]
 

    Constraints:

        1 <= nums.length <= 104
        -2**31 <= nums[i] <= 2**31 - 1


*/


#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
    if (nums.size() == 1)
        return;
    
/* TC O(N**2)
    for (int i = 0; i < nums.size(); i++) {
        if ((nums[i] == 0) && (i < nums.size()-1)) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[j]) {
                    nums[i] = nums[j];
                    nums[j] = 0;
                    break;
                }
            }
        }
    }
*/
    // TC O(N)
    int j = -1;                     // Will always point to last non-zero, initial unknown
    int n = nums.size();
    
    // Scan thru every number in the list, swap non-zero with zero (next j)
    for(int i = 0; i < n; i++) {
        if(nums[i] != 0) {
            swap(nums[++j], nums[i]);
        }
    }
    return;
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
    vector<int> nums = { 0,1,0,3,12 };

    printArray("Input: ", nums);
    moveZeroes(nums);
    printArray("Output: ", nums);

}


