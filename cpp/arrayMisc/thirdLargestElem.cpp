// C++ program to find third
// Largest element in an array
//#include <bits/stdc++.h>

//
// 1. Simple O(n) algorithm below.
//
// 2. Sort array in ascending order and locate 3rd largest from the end of array
//
// 3. Using maxHeap to maintain descending order list, 3rd largest is located from
//    the top element down. NOTE: maxHeap allows duplicate entries so we need to 
//    skip duplicates. 
//
//

#include <iostream>
#include <vector>

using namespace std;
 
void thirdLargest(vector<int> arr)
{
    /* There should be at least three elements */
    if (arr.size() < 3)
    {
        printf(" Invalid Input!\n");
        return;
    }
 
    // Initialize first, second and third Largest element
    int first = arr[0], second = INT_MIN, third = INT_MIN;
 
    // Traverse array elements to find the third Largest
    for (int i = 1; i < arr.size(); i ++)
    {
        if (arr[i] == first || arr[i] == second || arr[i] == third)
            continue;   // skip duplicates

        /* If current element is greater than first,
           then update first, second and third */
        if (arr[i] > first)
        {
            third  = second;
            second = first;
            first  = arr[i];
        }
 
        /* If arr[i] is in between first and second */
        else if (arr[i] > second)
        {
            third = second;
            second = arr[i];
        }
 
        /* If arr[i] is in between second and third */
        else if (arr[i] > third)
            third = arr[i];
    }
 
    printf("\nThe third Largest element is %d\n", third);
}
 
/* Driver program to test above function */
int main()
{
    vector<int> nums;
    int num;

    while (1) {
        nums = {};
        cout << "Enter numbers separated by white space (0 to terminate): ";
        while (cin >> num) { //enter any non-integer to end the loop!
            if (num == 0)
                break;
            cout << num << " ";
            nums.push_back(num);
        }
        if (nums.size() == 0)
            break;  // terminate loop

        thirdLargest(nums);
    }
    return 0;
}
