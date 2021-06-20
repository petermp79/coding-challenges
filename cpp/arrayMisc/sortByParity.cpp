/*

  Given an array A of non-negative integers, return an array consisting of all the even 
  elements of A, followed by all the odd elements of A.

  You may return any answer array that satisfies this condition.

  Input: [3,1,2,4]
  Output: [2,4,3,1]
  The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> sortArrayByParity(vector<int>& A) {
    if (A.size() <= 1)
        return A;
    
    // TC O(N) SC O(1)
    int l = 0;
    int r = A.size()-1;
    
    // Partition array so that all even numbers on the left and odd numbers on the right
    while (l < r) {
        while (l < r && (A[l] % 2) == 0) l++;
        while (l < r && (A[r] % 2) == 1) r--;
               
        int tmp = A[l];
        A[l] = A[r];
        A[r] = tmp;
    }
    return A;
}

int main() {
    vector<int> A = { 3, 2, 1, 4, 6, 5 };

    A = sortArrayByParity(A);

    for (int i : A)
        cout << i << " ";

    cout << endl;

    return 0;
}


