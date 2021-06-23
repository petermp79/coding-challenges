/*

    LEETCODE# 485

    Given a binary array nums, return the maximum number of consecutive 1's in the array.

    Example 1:

    Input: nums = [1,1,0,1,1,1]
    Output: 3
    Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of 
    consecutive 1s is 3.

    Example 2:

    Input: nums = [1,0,1,1,0,1]
    Output: 2
 

    Constraints:

        1 <= nums.length <= 10^5
        nums[i] is either 0 or 1.


*/

#include <iostream>
#include <vector>

using namespace std;

int findMaxConsecutiveOnes(vector<int> nums) {
    int max = 0;
    int cnt = 0;
    int elems = 0;
    
    for (int i : nums) {
        elems++;
        if (i & 1) {
            cnt++;      // counting consecutive ones
        }
        else if (cnt > max) {
            //std::cout << elems << "-" << max << ":" << cnt << endl;
            max = cnt;
            cnt = 0;    // reset counter
        }
   
    }

    //std::cout << elems << "-" << max << ":" << cnt << endl;
    max = cnt > max ? cnt : max;
    return max;
}

int main() {

    cout << "Input: [1,1,0,1,1,1] --> " << findMaxConsecutiveOnes({1,1,0,1,1,1}) << endl;
    cout << "Input: [1,0,1,1,0,1] --> " << findMaxConsecutiveOnes({1,0,1,1,0,1}) << endl;

    // WARNING: this function does not pass LEETCODE test suite
    return 0;
}


