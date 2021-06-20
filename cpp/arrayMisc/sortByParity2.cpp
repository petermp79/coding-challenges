/*

   Given an array of integers nums, half of the integers in nums are odd, and the other half are even.

   Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.

   Return any answer array that satisfies this condition.

   Input: nums = [4,2,5,7]
   Output: [4,5,2,7]
   Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.

 */

#include <iostream>
#include <vector>

using namespace std;

// TC O(N) SC O(1)
vector<int> sortArrayByParity2(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1)
        return nums;
    
    // TC O(N) SC O(1)
    int even = 0;
    int odd = 1;
    
    // Partition array so that all even numbers on the left and odd numbers on the right
    while (even < n && odd < n) {
        while ((even < n) && (nums[even] % 2 == 0)) even += 2; // scan for even index, odd value
        while ((odd < n) && (nums[odd] % 2 == 1)) odd += 2;    // scan for odd index, even value
            
        if (even < n && odd < n) {
            int tmp = nums[even];
            nums[even] = nums[odd];
            nums[odd] = tmp;
        }
    }   
        
    return nums;
}

int main() {
    vector<int> A = { 3, 2, 1, 4, 6, 5 };

    A = sortArrayByParity2(A);

    for (int i : A)
        cout << i << " ";

    cout << endl;

    return 0;
}


