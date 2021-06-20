/*
    Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that 
    each unique element appears only once. The relative order of the elements should be kept the same.

    Since it is impossible to change the length of the array in some languages, you must instead have the 
    result be placed in the first part of the array nums. More formally, if there are k elements after 
    removing the duplicates, then the first k elements of nums should hold the final result. It does not 
    matter what you leave beyond the first k elements.

    Return k after placing the final result in the first k slots of nums.

    Do not allocate extra space for another array. You must do this by modifying the input array in-place 
    with O(1) extra memory.

    Custom Judge:

    The judge will test your solution with the following code:

    int[] nums = [...]; // Input array
    int[] expectedNums = [...]; // The expected answer with correct length

    int k = removeDuplicates(nums); // Calls your implementation

    assert k == expectedNums.length;
    for (int i = 0; i < k; i++) {
        assert nums[i] == expectedNums[i];
    }
    If all assertions pass, then your solution will be accepted.
 

    Example 1:

    Input: nums = [1,1,2]
    Output: 2, nums = [1,2,_]
    Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
                 It does not matter what you leave beyond the returned k (hence they are underscores).

    Example 2:

    Input: nums = [0,0,1,1,1,2,2,3,3,4]
    Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
    Explanation: Your function should return k = 5, with the first five elements of nums being 
                 0, 1, 2, 3, and 4 respectively.

    It does not matter what you leave beyond the returned k (hence they are underscores).
 

    Constraints:

        0 <= nums.length <= 3 * 104
        -104 <= nums[i] <= 104
        nums is sorted in non-decreasing order.
*/

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    // Check for edge cases.
    if (nums.size() == 0) {
        return 0;
    }
    // Time O(N) - Space O(1)
    // - Use the two pointer technique to remove the duplicates in-place, read and write pointers. 
    // - Init read/write pointers to second elem
    // - Advance readpointer and check if the next num is different than the previous one.
    //      if it is, copy num@read pointer to where write pointer points to.
    //      if they are the same, advance readpointer to next char and repeat the checking
    // - At end of string, the writepointer is the arr length after duplicates removed
    //
    int writePointer = 1;
    
    // Go through each num in the Array.
    for (int readPointer = 1; readPointer < nums.size(); readPointer++) {
        if (nums[readPointer] != nums[readPointer - 1]) {
            nums[writePointer++] = nums[readPointer];
        }
        // Else, if it is the same as previous num, skip it (not write)
    }
  
    // At the end, write point reflects the length.
    return writePointer;
}

int main() {
    vector<int> array = {1, 2, 2, 3, 4, 5, 5, 5, 6, 7, 7, 8};

    cout << "Array: ";
    for (int i = 0; i < array.size(); i++)
        cout << array[i] << ", ";
    cout << endl;

    int len = removeDuplicates(array);
    cout << "Result: ";
    for (int i = 0; i < len; i++)
        cout << array[i] << ", ";
    cout << endl;
}
