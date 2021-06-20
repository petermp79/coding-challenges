/*

    LEETCODE #31

    Implement next permutation, which rearranges numbers into the lexicographically next greater 
    permutation of numbers.

    If such an arrangement is not possible, it must rearrange it as the lowest possible order 
    (i.e., sorted in ascending order).

    The replacement must be in place and use only constant extra memory.

 

    Example 1:
        Input: nums = [1,2,3]
        Output: [1,3,2]

    Example 2:
        Input: nums = [3,2,1]
        Output: [1,2,3]

    Example 3:
        Input: nums = [1,1,5]
        Output: [1,5,1]

    Example 4:
        Input: nums = [1]
        Output: [1]
 

    Constraints:
        1 <= nums.length <= 100
        0 <= nums[i] <= 100

*/

#include <iostream>
#include <vector>

using namespace std;

void nextPermutation(vector<int>& nums) {
    int i, j;
    
    if (nums.size() <= 1)
        return;
    
    // 1/ From the right->left, find the "highest" index i where s[i] < s[i+1]
    //    E.g:  1 4 3 2 5 --> i = 3 (2 < 5)
    //          1 4 3 5 2 --> i = 3 (3 < 5)
    //
    for (i = nums.size()-2; i >= 0; i--) {
        if (nums[i] < nums[i+1])
            break;
    }
    
    if (i < 0) {
        // If not found, nums are already in reversed order, 
        // ... next perm is sorted order (wrap-around)
        sort(nums.begin(), nums.end());
        return;
    }
    
    // 2/ Find the index j where s[j] next> s[i]. This is the one to replace item i
    //    e.g. 1 4 3 2 5 --> i = 3, j = 4 --> 1 4 3 5 2
    //         1 4 3 5 2 --> i = 2, j = 3 --> 1 4 5 2 3 (swap 3 & 5 then sort 3 & 2) 
    //
    int diff = 0, closest = i+1;
    for (j = i+1; j < nums.size(); j++) {
        if (nums[j] > nums[i]) {
            int d = nums[j] - nums[i];      // calculate the difference between i and j
            if (diff == 0 || d < diff) {    // if diff is < previous diff, set it to closest
                diff = d;
                closest = j;
            }
        }
    }
    j = closest;

    // 3/ Swap nums @ i and j --> 1 4 5 3 2
    //
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
    
    // 4/ Sort all nums after item i --> 1 4 5 2 3
    //
    sort(nums.begin()+i+1, nums.end());
    
}


// Function to get multiple input on the same line
// Optionally, output input data for visual inspection
//

#include <sstream>

vector<int> getMultiInput(string msg, bool output) {
    vector<int> inputs{}; 
    std::string line;
    int data = 0;

    cout << msg;

    cin >> data;
    inputs.push_back(data);

    // get the rest input data
    std::getline(std::cin, line);
    std::istringstream input(line);
    while (input >> data) {
        inputs.push_back(data);
    }

    if (output) {
        for (auto data : inputs) {
            cout << data << " ";
        }
        cout << endl;
    }
    return inputs;
}

int main() {

    while (1) {
        vector<int> nums = getMultiInput("Enter list of numbers (^C to quit): ", true);
        nextPermutation(nums);
        cout << "Result: ";
        for (auto data : nums) {
            cout << data << " ";
        }
        cout << endl;
    }
}
