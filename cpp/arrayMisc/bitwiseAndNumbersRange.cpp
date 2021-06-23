/*

    LEETCODE: 201

    Given two integers left and right that represent the range [left, right], return the bitwise AND 
    of all numbers in this range, inclusive.

 

    Example 1:

    Input: left = 5, right = 7
    Output: 4

    Example 2:

    Input: left = 0, right = 0
    Output: 0

    Example 3:

    Input: left = 1, right = 2147483647
    Output: 0
 

    Constraints:
    
    0 <= left <= right <= 231 - 1

*/

#include <iostream>

using namespace std;

int rangeBitwiseAnd(int left, int right) {
    int count = 0;
    
    // 1) Find position of Most Significant Bit (MSB) in both numbers, msb_p.
    // 2) If positions of MSB are different, then result is 0. 
    // 3) If positions are same. Let positions be msb_p, return 2**msb_p as result. 
        
    while (left != right) {
        left >>= 1;
        right >>= 1;
        count++;
    }
    // If msb_p of left and right are different, left & right will end up = 0
    // If they are the same position, left and right will end up = 1
    return left << count;
}


int main() {

    cout << "[5, 7]: " << rangeBitwiseAnd(5, 7) << endl;

    cout << "[0, 0]: " << rangeBitwiseAnd(0, 0) << endl;

    cout << "[1, 2147483647]: " << rangeBitwiseAnd(1, 2147483647) << endl;

}


