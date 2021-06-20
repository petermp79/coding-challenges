/*

   Given two integers dividend and divisor, divide two integers without using multiplication, division, 
   and mod operator.

   Return the quotient after dividing dividend by divisor.

   The integer division should truncate toward zero, which means losing its fractional part. For example, 
   truncate(8.345) = 8 and truncate(-2.7335) = -2.

   Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer 
   range: [−231, 231 − 1]. For this problem, assume that your function returns 231 − 1 when the division result 
   overflows.

*/

#include <iostream>
#include <vector>

using namespace std;

int divide(int dividend, int divisor) {
   if (dividend == INT_MIN and divisor == -1)
        return INT_MAX;
 
    long long num = abs(dividend), denm = abs(divisor), quotient = 0;
    int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
    
    while (num >= denm)
    {
        long long temp = denm, m = 1;
        while (temp << 1 <= num)
        {
            temp <<= 1;
            m <<= 1;
            //cout << temp << "." << m << endl;
        }
 
        num -= temp;
        quotient += m;
    }
    return (int)(sign * quotient);
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

        cout << "\nQuotient: " << divide(nums[0], nums[1]) << endl << endl;
    }
    return 0;
}


