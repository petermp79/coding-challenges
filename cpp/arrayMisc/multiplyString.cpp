/*

   Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, 
   also represented as a string.

   Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

*/


#include <iostream>

using namespace std;


string multiply(string num1, string num2) {
    // allocate space for result string
    string result(num1.size()+num2.size(), '0');

    for(int i = num1.size()-1; i>=0; i--){
        for(int j = num2.size()-1; j>=0; j--){
            int prod = (num1[i]-'0')*(num2[j]-'0') + (result[i+j+1]-'0');
            int carry = prod / 10;
            int rem = prod % 10;
            result[i+j+1] = rem+'0';
            result[i+j] = (carry + (result[i+j]-'0')) + '0';
        }
    }
    int it = result.find_first_not_of("0");
    return ( it < 0  ? "0" : result.substr(it) );
}


int main() {
    cout << multiply("123456", "654321") << endl;
}

