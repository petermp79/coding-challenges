//
// LEETCODE# 88
//
// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
// The number of elements initialized in nums1 and nums2 are m and n respectively. 
// You may assume that nums1 has a size equal to m + n such that it has enough space to hold 
// additional elements from nums2.
//
//
// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Input: nums1 = [1], m = 1, nums2 = [], n = 0
// Output: [1]
//
// Constraints:
//    - nums1.length == m + n
//    - nums2.length == n
//    - 0 <= m, n <= 200
//    - 1 <= m + n <= 200
//    - -109 <= nums1[i], nums2[i] <= 109
//

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> result{};
    int n1 = 0;
    int n2 = 0;
    
    if (m == 0) {
        // first array empty, fill in 2nd array
        nums1.assign(nums2.begin(), nums2.end());
        return;
    }
    if (n == 0) {
        // second array empty, no merge
        return;
    }
    
    // merge elems in 2 arrays until either one is done
    while ((n1 < m) && (n2 < n)) {
        if (nums1[n1] <= nums2[n2]) {
            result.push_back(nums1[n1++]);
        } else {
            result.push_back(nums2[n2++]);
        }
    }
    // append the remaining elems of the other arrays if any
    while (n1 < m)
        result.push_back(nums1[n1++]);

    while (n2 < n)
        result.push_back(nums2[n2++]);
    
    nums1.assign(result.begin(), result.end());
}


