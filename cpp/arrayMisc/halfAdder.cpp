
// C++ Program to add two numbers without using arithmetic operator 

#include <iostream>

using namespace std;


int Add(int x, int y) 
{ 
    // Iterate till there is no carry 
    cout << "Adding " << x << " + " << y << endl;

    while (y != 0) 
    { 
        cout << "------" << endl;

        // carry now contains common 
        //set bits of x and y 
        int carry = x & y; 

        cout << "x: " << bitset<32>(x) << endl;
        cout << "y: " << bitset<32>(y) << endl;
        cout << "c: " << bitset<32>(carry) << endl;
 
        // Sum of bits of x and y where at 
        //least one of the bits is not set 
        x = x ^ y; 
 
        cout << "x: " << bitset<32>(x) << endl;
 
        // Carry is shifted by one so that adding 
        // it to x gives the required sum 
        y = carry << 1; 

        cout << "y: " << bitset<32>(y) << endl;

    } 

    return x; 
} 
 
// Driver code
int main() 
{ 
    cout << Add(15, 32) << endl << endl; 
    cout << Add(16, 43) << endl << endl; 
    cout << Add(9, 14) << endl << endl; 
    return 0; 
} 



