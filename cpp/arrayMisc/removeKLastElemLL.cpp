/*

   This problem was asked by Google.

   Given a singly linked list and an integer k, remove the kth last element from the list. 
   k is guaranteed to be smaller than the length of the list.

   The list is very long, so making more than one pass is prohibitively expensive.
   
   Do this in constant space and in one pass.

   Solution:

    Use two pointers, one after the other K position. When the forward one reaches the end
    of the list, the second one will reach the Kth elem.

    Then remove all nodes from the second pointer.

*/

