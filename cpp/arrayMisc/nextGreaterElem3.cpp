/*

   Given a positive integer n, find the smallest integer which has exactly the same digits existing in the 
   integer n and is greater in value than n. If no such positive integer exists, return -1.

   Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not 
   fit in 32-bit integer, return -1.

   Example 1:
     Input: n = 12
     Output: 21

   Example 2:
     Input: n = 21
     Output: -1

*/

#include <iostream>
#include <string>

using namespace std;

int nextGreaterElement(int n) {
    string s = to_string(n);
    int i, j;
    
    // From the right, find the first number less than the previous one on the right
    for (i = s.size()-2; i >= 0; i--) {
        if (s[i] < s[i+1]) 
            break;
    }
    
    if (i == -1) 
        return -1;  // if not found, return -1
    
    // From the right, find the first number greater than the result of the above step
    for (j = s.size()-1; j > i; j--) {
        if (s[j] > s[i])
            break;
    }
    
    swap(s[i], s[j]);                   // swap them
    
    reverse(s.begin()+(i+1), s.end());  // reverse all numbers after the position of i
    
    try {
        i = stoi(s);
    }
    catch (...) {   // catch all exceptions: out of range exception, etc.
        i = -1;
    }
   
    return i;
}

int main() {
    
    cout << "Result 12345: " << nextGreaterElement(12345) << endl;
    cout << "Result 54321: " << nextGreaterElement(54321) << endl;
    cout << "Result 1999999999: " << nextGreaterElement(1999999999) << endl;
    cout << "Result: INT_MAX " << nextGreaterElement(INT_MAX) << endl;
}


