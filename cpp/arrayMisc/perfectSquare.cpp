/*

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Follow up: Do not use any built-in library function such as sqrt.

Example 1:

    Input: num = 16
    Output: true

Example 2:

    Input: num = 14
    Output: false
 

Constraints:

    1 <= num <= 2^31 - 1


Solution:
    Probe a number x such that x*x = n --> square. 
    If x cant be found, not a sqaure.

    Use binary search in the range of 1 to N.

    TC O(log(sqrt(n)));

*/

#include <iostream>
#include <cmath>

using namespace std;

bool isSquare(int n) {
    int left = 1;
    int right = n > 46341 ? 46341 : n;  // 46341 --> sqrt(INT_MAX)
    int mid;


    while (left <= right) {
        mid = left + (right-left)/2;

        int midSquare = mid * mid;
        //cout << mid << "." << midSquare << endl;

        if (midSquare == n)
            return true;
        else if (midSquare <= n)
            left = mid+1;
        else
            right = mid-1;
    }
    return false;
}

int main() {

    //cout << sqrt(INT_MAX) << endl;

    cout << "16 -->" << isSquare(16) << endl;
    cout << "24 -->" << isSquare(24) << endl;
    cout << "500 -->" << isSquare(500) << endl;
    cout << "10000 -->" << isSquare(10000) << endl;
    cout << "1000000 -->" << isSquare(1000000) << endl;

    return 0;
}

