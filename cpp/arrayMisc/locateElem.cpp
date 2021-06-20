/*
   Good morning! Here's your coding interview problem for today.

   This problem was asked by Amazon.

   An sorted array of integers was rotated an unknown number of times.

   Given such an array, find the index of the element in the array in faster than linear time. 
   If the element doesn't exist in the array, return null.

   For example, given the array [13, 18, 25, 2, 8, 10] and the element 8, return 4 (the index 
   of 8 in the array).

   You can assume all the integers in the array are unique.
*/

#include <iostream>
#include <array>

using namespace std;

int main() {
    array<int, 6> arr{13, 18, 25, 2, 8, 10};
    int n;
    int i;

    for (i = 0; i < arr.size(); i++)
        cout << arr[i] << ", ";
    cout << endl;

    while (1) {

        cout << "Enter an element (or 0 to quit): ";
        cin >> n;
        if (n == 0)
            return 0;

        if (n == arr[0]) {
            cout << "Index: 0" << endl;
        }
        else if (n < arr[0]) {
            for (i = arr.size()-1; i >= 0; i--) {
                if (n == arr[i]) {
                    cout << "Index: " << i << endl;
                    break;
                } 
            }
        }
        else {
            for (i = 1; i < arr.size(); i++) {
                if (n == arr[i]) {
                    cout << "Index: " << i << endl;
                    break;
                } 
            }
        } 
        cout << "Element not found!" << endl;
    }
}

