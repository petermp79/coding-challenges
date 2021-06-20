/*

   This problem was asked by Google.

   Given an array of integers where every integer occurs three times except for one integer, which only occurs 
   once, find and return the non-duplicated integer.

   For example, given [6, 1, 3, 3, 3, 6, 6], return 1. Given [13, 19, 13, 13], return 19.

   Do this in O(N) time and O(1) space.

*/

#include <iostream>
#include <map>

using namespace std;

int getSingle(int arr[], int n)
{
    int ones = 0, twos = 0;
 
    int common_bit_mask;
 
    // Let us take the example of
    // {3, 3, 2, 3} to understand
    // this
    for (int i = 0; i < n; i++) {
       
        /* The expression "one & arr[i]" gives the bits that
        are there in both 'ones' and new element from arr[].
        We add these bits to 'twos' using bitwise OR
 
        Value of 'twos' will be set as 0, 3, 3 and 1 after
        1st, 2nd, 3rd and 4th iterations respectively */
        twos = twos | (ones & arr[i]);
 
        /* XOR the new bits with previous 'ones' to get all
        bits appearing odd number of times
 
        Value of 'ones' will be set as 3, 0, 2 and 3 after
        1st, 2nd, 3rd and 4th iterations respectively */
        ones = ones ^ arr[i];
 
        /* The common bits are those bits which appear third
        time So these bits should not be there in both
        'ones' and 'twos'. common_bit_mask contains all
        these bits as 0, so that the bits can be removed
        from 'ones' and 'twos'
 
        Value of 'common_bit_mask' will be set as 00, 00, 01
        and 10 after 1st, 2nd, 3rd and 4th iterations
        respectively */
        common_bit_mask = ~(ones & twos);
 
        /* Remove common bits (the bits that appear third
        time) from 'ones'
 
        Value of 'ones' will be set as 3, 0, 0 and 2 after
        1st, 2nd, 3rd and 4th iterations respectively */
        ones &= common_bit_mask;
 
        /* Remove common bits (the bits that appear third
        time) from 'twos'
 
        Value of 'twos' will be set as 0, 3, 1 and 0 after
        1st, 2nd, 3rd and 4th itearations respectively */
        twos &= common_bit_mask;
 
        // uncomment this code to see intermediate values
        // printf (" %d %d n", ones, twos);
    }
 
    return ones;
}
 
/*
   Following is another O(n) time complexity and O(1) extra space method suggested by aj. 
   We can sum the bits in same positions for all the numbers and take modulo with 3. 
   The bits for which sum is not multiple of 3, are the bits of number with single occurrence. 
   Let us consider the example array {5, 5, 5, 8}. The 101, 101, 101, 1000 

        1 0 1
        1 0 1
        1 0 1
      1 0 0 0

   Sum of first bits%3 = (1 + 1 + 1 + 0)%3 = 0; 
   Sum of second bits%3 = (0 + 0 + 0 + 0)%0 = 0; 
   Sum of third bits%3 = (1 + 1 + 1 + 0)%3 = 0; 
   Sum of fourth bits%3 = (1)%3 = 1; 

   Hence number which appears once is 1000
*/

#define INT_SIZE 32
 
int getSingle2(int arr[], int n)
{
    // Initialize result
    int result = 0;
 
    int x, sum;
 
    // Iterate through every bit
    for (int i = 0; i < INT_SIZE; i++) {
 
        // Find sum of set bits at ith position in all
        // array elements
        sum = 0;
        x = (1 << i);
        for (int j = 0; j < n; j++) {
            if (arr[j] & x)
                sum++;
        }
 
        // The bits with sum not multiple of 3, are the
        // bits of element with single occurrence.
        if ((sum % 3) != 0)
            result |= x;
    }
 
    return result;
}

 
// Driver code
int main()
{
    //int arr[] = { 3, 3, 2, 3, 1, 1, 1 };
    int arr[] = { 12, 1, 12, 3, 12, 1, 1, 2, 3, 2, 2, 3, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "1. The element with single occurrence is  "
         << getSingle(arr, n) << endl;
    cout << "2. The element with single occurrence is  "
         << getSingle2(arr, n) << endl;

    return 0;
}


