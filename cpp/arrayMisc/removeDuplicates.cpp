//
//
// Given a sorted array nums, remove the duplicates in-place such that each element appears only once 
// and returns the new length.
//
// Do not allocate extra space for another array, you must do this by modifying the input array in-place 
// with O(1) extra memory.
//
//

public int removeDuplicates(int[] nums) {
        
  // Check for edge cases.
  if (nums == null) {
      return 0;
  }
  
  // Use the two pointer technique to remove the duplicates in-place.
  // read pointer -- current read
  // write pointer -- current write
  // Init:   read = write = 1  --- The first element shouldn't be touched; it's already in its correct place
  // 
  // If they are equal, copy cur char to write location and advance write to the next location
  //
  int writePointer = 1;
  // Go through each element in the Array.
  for (int readPointer = 1; readPointer < nums.length; readPointer++) {
      // While advancing read pointer, compare it with the immediate prev char
      // If the current element we're reading is *different* to the previous element...
      if (nums[readPointer] != nums[readPointer - 1]) {
          // Copy it into the next position at the front, tracked by writePointer.
          nums[writePointer] = nums[readPointer];
          // And we need to now increment writePointer, because the next element
          // should be written one space over.
          writePointer++;
      }
  }
  
  // This turns out to be the correct length value.
  return writePointer;
}


