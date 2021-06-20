/*
    LEETCODE# 7

    Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes 
    the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

    Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

    Example 1:
        Input: x = 123
        Output: 321

    Example 2:
        Input: x = -123
        Output: -321

    Example 3:
        Input: x = 120
        Output: 21

    Example 4:
        Input: x = 0
        Output: 0
 

    Constraints:

        -2**31 <= x <= 2**31 - 1

*/

#include <iostream>

using namespace std;

int reverseInteger(int x) {
    bool negative = x < 0 ? true : false;
    long res = 0L;
    
    x = abs(x);             // x = 123
    
    while (x > 0) {
        int m = x % 10;     // m = 3, 2, 1
        x = x / 10;         // x = 12, 1, 0
        res = res*10 + m;   // x = 3, 32, 321
        if (res > INT_MAX)
            return 0;
    }
    
    if (negative)
        res = -res;
    
    return res;
}

int main() {

    cout << "Reverse (123): " << reverseInteger(123) << endl;
    cout << "Reverse (7890): " << reverseInteger(7890) << endl;
    cout << "Reverse (0123456789): " << reverseInteger(123456789) << endl;
}

