/*

  You are given two integer arrays nums1 and nums2 both of unique elements, where nums1 is a subset of nums2.

  Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

  The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. 
  If it does not exist, return -1 for this number.

 

  Example 1:
  ----------
   Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
   Output: [-1,3,-1]

  Explanation:
   For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
   For number 1 in the first array, the next greater number for it in the second array is 3.
   For number 2 in the first array, there is no next greater number for it in the second array, so output -1.

  Example 2:
  ----------
    Input: nums1 = [2,4], nums2 = [1,2,3,4]
    Output: [3,-1]

  Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
 
  Constraints:
  ------------
    1 <= nums1.length <= nums2.length <= 1000
    0 <= nums1[i], nums2[i] <= 104
    All integers in nums1 and nums2 are unique.
    All the integers of nums1 also appear in nums2.
 
  Follow up: Could you find an O(nums1.length + nums2.length) solution?

*/

#include <iostream>
#include <vector>
#include <deque>
#include <map>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result{};       // result
    deque<int> stack{};         // stack of element indices for determining NextGreater elems
    map <int, int> hashmap{};   // <number, next greater of it>
    int idx = -1;               // index of nums2 
    
    // Step1 - build next greater hashmap corresponding to nums2
    
    for (int i = 0; i < nums2.size(); i++) {
        if (stack.empty()) {        // first number in nums2?
            stack.push_front(i);
            continue;
        }
        else {
            idx = stack.front();
            if (nums2[i] <= nums2[idx]) {
                // if cur number is <= prev one, push to top of stack (save)
                stack.push_front(i);
            }
            else {
                // if cur number is > prev one, it is next greater of prev one(s) on stack
                
                // pop out prev one(s) until cur number is less then one on stack or when stack is empty
                while (nums2[idx] < nums2[i] && !stack.empty()) {
                    //cout << "hashmap: " << nums2[idx] << "=" << nums2[i] << endl;
                    hashmap[nums2[idx]] = nums2[i];
                    stack.pop_front();
                    if (stack.empty())
                        break;
                    idx = stack.front();
                }
                // put cur number on top of stack
                stack.push_front(i);
            }
        }
    }
    
    // Step2 - for every number in nums1, check if it has a corresponding next greater #
    
    for (int i = 0; i < nums1.size(); i++) {
        auto itr = hashmap.find(nums1[i]);
        if (itr != hashmap.end())
            result.push_back(itr->second);  // yes, here it is
        else
            result.push_back(-1);           // no greater number
    }
    
    return result;
}

int main() {
    vector<int> nums1 = {1, 3, 4};
    vector<int> nums2 = {4, 2, 1, 3, 5, 6};
    vector<int> result;

    result = nextGreaterElement(nums1, nums2); 

    cout << "List: ";
    for (int i = 0; i < nums2.size(); i++) {
        cout << nums2[i] << ", ";
    }
    cout << endl;

    cout << "Next greater element of: " << endl;
    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << "->" << result[i] << endl;
    }
}


