/*

Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.

Example 1:
    Input: nums = [2,3,1,1,4]
    Output: true
    Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
    Input: nums = [3,2,1,0,4]
    Output: false
    Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it 
        impossible to reach the last index.

*/


#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int> arr){
    
    // Tricky solution TC O(n) - SC O(1) 
    
    int maxIndex = 0;
    
    cout << "("; 
    for (int i = 0; i < arr.size(); i++) {
        if (i > maxIndex) {
            break;
        }
        else {
            maxIndex = max(maxIndex, i+arr[i]);
            if (maxIndex > arr.size()-1)
                break;
        }
        cout << maxIndex << ".";
    }
    cout << maxIndex << ") --> ";
    return maxIndex >= arr.size()-1;
}

int main() {
    cout << "If maxIndex = index+arr[index] > index of the last array entry --> true" << endl;

    cout << "{2, 3, 1, 1, 4} --> " << canJump({2, 3, 1, 1, 4}) << endl;
    cout << "{3, 2, 1, 0, 4} --> " << canJump({3, 2, 1, 0, 4}) << endl;
    cout << "{3, 0, 2, 0, 2, 1, 4, 3} --> " << canJump({3, 0, 2, 0, 2, 1, 4, 3}) << endl;
    cout << "{10, 0, 2, 0, 2, 1, 4, 3} --> " << canJump({10, 0, 2, 0, 2, 1, 4, 3}) << endl;
}

