/*

   LEETCODE# 349

   Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in 
   the result must be unique and you may return the result in any order.

   Example 1:

     Input: nums1 = [1,2,2,1], nums2 = [2,2]
     Output: [2]

   Example 2:

     Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
     Output: [9,4]
     Explanation: [4,9] is also accepted.

*/

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> hashmap;
    vector<int> result{};
    set<int> set{};             // use set to avoid duplicate 
    
    // Construct hashmap of numbers in one array
    //
    for (auto i : nums1) {
        hashmap.insert(i);
    }
    // Check for intersection in second array
    //
    for (auto i : nums2) {
        auto itr = hashmap.find(i);
        if (itr != hashmap.end()) {
            set.insert(i);          // Found intersection, save in set
        }
    }
    // Copy to vector for return
    //
    result.assign(set.begin(), set.end());
    return result;
}

int main() {
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    vector<int> result;

    cout << "[";
    for (auto i : nums1) {
        cout << i << ", ";
    }
    cout << "]" << endl;
    cout << "[";
    for (auto i : nums2) {
        cout << i << ", ";
    }
    cout << "]" << endl;

    result = intersection(nums1, nums2);

    cout << "==> [";
    for (auto i : result) {
        cout << i << ", ";
    }
    cout << "]" << endl;

}


