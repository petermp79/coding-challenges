/*

    LEETCODE# 239

    You are given an array of integers nums, there is a sliding window of size k which is moving from 
    the very left of the array to the very right. You can only see the k numbers in the window. Each time 
    the sliding window moves right by one position.

    Return the max sliding window.

    Example 1:

    Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
    Output: [3,3,5,5,6,7]
    Explanation: 
    Window position                Max
    ---------------               -----
    [1  3 -1] -3  5  3  6  7       3
    1 [3  -1  -3] 5  3  6  7       3
    1  3 [-1  -3  5] 3  6  7       5
    1  3  -1 [-3  5  3] 6  7       5
    1  3  -1  -3 [5  3  6] 7       6
    1  3  -1  -3  5 [3  6  7]      7

    Example 2:

    Input: nums = [1], k = 1
    Output: [1]

    Example 3:

    Input: nums = [1,-1], k = 1
    Output: [1,-1]

    Example 4:

    Input: nums = [9,11], k = 2
    Output: [11]

    Example 5:

    Input: nums = [4,-2], k = 2
    Output: [4]
 

    Constraints:

        1 <= nums.length <= 10**5
        -10**4 <= nums[i] <= 10**4
        1 <= k <= nums.length


*/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;


vector<int> maxSlidingWindow(vector<int> nums, int k) {
    deque<pair<int, int>> q; // <value, index>
    vector<int> result;
    
    // Maintain a queue of elems in descending order as we traverse 
    // the array from L->R so that the max num is always at the front
    // of the queue (O(N) time complexity - O(N) space)
    for (int i = 0; i < nums.size(); i++) {
        
        // Remove front elem if it is out of window boundary
        if (!q.empty() && q.front().second <= (i - k))
            q.pop_front();

        // Remove all elems in the back if they are less than current num
        // until queue is either empty or an elem >= current num is found
        while (!q.empty() && q.back().first < nums[i]) {
            q.pop_back();
        }
        
        // Insert new elem to back of queue
        q.push_back(make_pair(nums[i], i));

        // if k elems accounted for, save the front elem in the result list
        if (i >= k - 1) {
            result.push_back(q.front().first);
        }
    }
    return result;
    
}

// Print values in an array
//
void printArray(string heading, vector<int> array, int len=0) {
    if (len == 0)
        len = array.size();

    cout << heading << "[";
    for (int i = 0; i < len; i++) {
        cout << array[i] << ",";
    }
    cout << "]" << endl;
}

int main() {
    vector<int> array = { 1,3,-1,-3,5,3,6,7 };
    vector<int> result;

    printArray("Input: k=3, ", array);
    result =  maxSlidingWindow(array, 3);
    printArray("Output: ", result);

    return 0;
}

