/*
  Given a non-empty array of decimal digits representing a non-negative integer, 
  increment one to the integer.
  
  The digits are stored such that the most significant digit is at the head of the list, 
  and each element in the array contains a single digit.

  You may assume the integer does not contain any leading zero, except the number 0 itself.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    
    if (n == 0) 
        return digits;
   
    vector<int> result(n+1, 0);
 
    int carry = 1;
    int i = n;
    while (carry) {
        if (i > 0)
            result[i] = digits[i-1] + carry;
        else
            result[i] = carry;

        carry = result[i] / 10;
        result[i] = result[i] % 10;
        i--;
    }

    while (i > 0) {
        result[i] = digits[i-1];
        i--;
    }

    if (result[0] == 0)
        result.erase(result.begin());
    
    return result;
}

int main() {
    //vector<int> digits { 1, 2, 3 };
    //vector<int> digits { 9 };
    //vector<int> digits { 1, 9, 9 };
    vector<int> digits{};

    cout << "Enter numbers between 0 and 9 (e to end): ";
    int n;
    while (cin >> n) {
        if (cin.fail())
            break;
        digits.push_back(n);
    }
    auto result = plusOne(digits);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

