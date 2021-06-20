/*

  Given a number represented by a list of digits, find the next greater permutation of a number, in terms of 
  lexicographic ordering. If there is not greater permutation possible, return the permutation with the lowest 
  value/ordering.

  For example, the list [1,2,3] should return [1,3,2]. The list [1,3,2] should return [2,1,3]. 
  The list [3,2,1] should return [1,2,3].

  Can you perform the operation without allocating extra memory (disregarding the input memory)?

*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> nextGreaterElement(vector<int> nums) {
    int i, j;
    
    // From the right, find the first i where nums[i] < nums[i+1]
    for (i = nums.size()-2; i >= 0; i--) {
        if (nums[i] < nums[i+1]) 
            break;
    }

    if (i == -1) { 
        // not found, reverse the numbers
        reverse(nums.begin(), nums.end());
        return nums;
    } 

    // From the right, find the first j where nums[j] > nums[i]
    for (j = nums.size()-1; j > i; j--) {
        if (nums[j] > nums[i])
            break;
    }

    // swap nums[i] and nums[j]
    swap(nums[i], nums[j]);
    
    // reverse numbers from i+1 to end of list
    reverse(nums.begin()+(i+1), nums.end());
    
    return nums;
}

string printNums(vector<int> nums) {
    string s;

    for (auto i : nums) {
        s += to_string(i) + " ";
    }
    return s;
}

int main() {
    vector<int> nums{1, 2, 3};

    cout << "Result [1,2,3]: " << printNums(nextGreaterElement(nums)) << endl;

    nums = {1, 3, 2};
    cout << "Result [1,3,2]: " << printNums(nextGreaterElement(nums)) << endl;

    nums = {3, 2, 1};
    cout << "Result [3,2,1]: " << printNums(nextGreaterElement(nums)) << endl;

    nums = {1, 2, 3, 5, 4};
    cout << "Result [1, 2, 3, 5, 4]: " << printNums(nextGreaterElement(nums)) << endl;
}


