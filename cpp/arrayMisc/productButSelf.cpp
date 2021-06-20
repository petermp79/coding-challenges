/*
    LETTCODE# 238

    Given an integer array nums, return an array answer such that answer[i] is equal to the product 
    of all the elements of nums except nums[i].

    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

    You must write an algorithm that runs in O(n) time and without using the division operation.

 

    Example 1:
    
    Input: nums = [1,2,3,4]
    Output: [24,12,8,6]

    Example 2:

    Input: nums = [-1,1,0,-3,3]
    Output: [0,0,9,0,0]
 

    Constraints:

        2 <= nums.length <= 105
        -30 <= nums[i] <= 30

    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.


*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int> nums) {
        int n = nums.size();
        vector<int> result(n, 0);
    
        if(n < 1)
            return result;
        
        // TC O(n) SC O(n)
        
        // 1. Calculate accumulative product from left to right
        int product = 1;
        for(int i = 0; i < n; ++i)
        {
            product *= nums[i];
            result[i] = product;  
        }
      
        //for (auto x : result) cout << x << ".";
        //cout << endl;
        
        // 2. Calculate accumulative product from right to left and update result array
        // in one loop
        product = 1;
        for(int i = n-1; i > 0; --i)
        {
            result[i] = result[i-1]*product;
            product *= nums[i];
        }
        result[0] = product;
        
        //for (auto x : result) cout << x << ".";
        //cout << endl;
        
        return result;
}

// Print values in an array
//
void printArray(string heading, vector<int> array) {
    cout << heading << "[";
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << ",";
    }
    cout << "]" << endl;
}

int main() {

    vector<int> result;

    result = productExceptSelf({1,2,3,4});
    printArray("[1,2,3,4] --> ", result);

    result = productExceptSelf({-1,1,0,-3,3});
    printArray("[-1,1,0,-3,3] --> ", result);

    return 0;
}



