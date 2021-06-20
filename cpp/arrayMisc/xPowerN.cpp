/*

   Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

   Example 1:

   Input: x = 2.00000, n = 10
   Output: 1024.00000

   Example 2:

   Input: x = 2.10000, n = 3
   Output: 9.26100

   Example 3:

   Input: x = 2.00000, n = -2
   Output: 0.25000
   Explanation: 2-2 = 1/22 = 1/4 = 0.25

*/

#include <iostream>

using namespace std;

double myPow(double x, int n) {

    // TC O(logN) SC O(1)
    double temp;
    
    if (n == 0)
        return 1;               // pow(x, 0) --> 1
    
    temp = myPow(x, n / 2);
    
    if (n % 2 == 0)
        return temp * temp;     // n is even
    else
    {
        // n is odd and ...
        if (n > 0)
            return x * temp * temp;     // ... positive
        else
            return (temp * temp) / x;   // ... negative
    }

}

int main() {

    cout << "myPow(10, 4): " << myPow(10, 4) << endl;
    return 0;
    
}


