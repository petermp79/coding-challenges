/*

    LEETCODE# 11

    Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate 
    (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) 
    and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the 
    container contains the most water.

    Notice that you may not slant the container.

 

    Example 1:


    Input: height = [1,8,6,2,5,4,8,3,7]
    Output: 49
    Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

    Example 2:

    Input: height = [1,1]
    Output: 1

    Example 3:

    Input: height = [4,3,2,1,4]
    Output: 16

    Example 4:

    Input: height = [1,2,1]
    Output: 2
 

    Constraints:
        n == height.length
        2 <= n <= 105
        0 <= height[i] <= 104


*/

#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int> height) {
    int hsize = height.size();
    int maxArea = 0;
    
    if (hsize <= 1)
        return 0;
    
/* time exceeded TC = O(n^2) SC = O(1)
    for (int i = 0; i < hsize-1; i++) {
        for (int j = i+1; j < hsize; j++) {
            int cheight = height[i] < height[j] ? height[i] : height[j];
            maxArea = max(maxArea, cheight * (j-i));
        }
    }
*/
    
    // 1. Use two indices, left = 0 and right = n-1 and a value max_area.
    // 2. Compute the max_area and compare against current max area
    // 3. Advance the index of which height is lesser
    // 4. Repeat 1-3 until l >= r

    int l = 0;
    int r = hsize-1;
 
    while (l < r) {
        // Calculating the max area
        maxArea = max(maxArea, min(height[l], height[r]) * (r - l));                
        if (height[l] < height[r])
            l += 1; 
        else
            r -= 1;
    }
  
    return maxArea;
}

int main() {

    cout << "Input [1,8,6,2,5,4,8,3,7]: " << maxArea({1,8,6,2,5,4,8,3,7}) << endl;
    cout << "Input [1,1]: " << maxArea({1,1}) << endl;
    cout << "Input [4,3,2,1,4]: " << maxArea({4,3,2,1,4}) << endl;
    cout << "Input [1,2,1]: " << maxArea({1,2,1}) << endl;
}


