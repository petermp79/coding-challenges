/*
   This problem was asked by Facebook.

   Given an array of integers, write a function to determine whether the array could become non-decreasing 
   by modifying at most 1 element.

   For example, given the array [10, 5, 7], you should return true, since we can modify the 10 into a 1 
   to make the array non-decreasing.

   Given the array [10, 5, 1], you should return false, since we can't modify any one element to get a 
   non-decreasing array.
*/

#include <iostream>
#include <vector>

using namespace std;

bool modify(vector<int> vec) {
    int cnt = 0;

    cout << endl;
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] <= vec[i-1]) {
            cout << vec[i-1] << " <= " << vec[i] << endl; 
            cnt++;
        }
    } 
    if (cnt <= 1)
        return true;
    else
        return false;
}

int main() {
    vector<int> vec;
    int n;

    cout << "Enter positive numbers (e to end): ";
    while (cin >> n) {
        if (cin.fail())
            break;
        cout << n << endl;
        vec.push_back(n);
    }
    cout << "Result: " << modify(vec) << endl;
    return 0; 
}
