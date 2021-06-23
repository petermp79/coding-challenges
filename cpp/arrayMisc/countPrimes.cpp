/*

    LEETCODE# 204

    Count the number of prime numbers less than a non-negative number, n.

 

    Example 1:

    Input: n = 10
    Output: 4
    Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

    Example 2:

    Input: n = 0
    Output: 0

    Example 3:

    Input: n = 1
    Output: 0
 

    Constraints:

        0 <= n <= 5 * 10**6


*/

#include <iostream>
#include <vector>

using namespace std;

// Prime number is a number divisible to 1 and itself only.
//
int countPrimes(int n) {
    int i, j, cnt = 0;
    
    if (n <= 1) {
        return 0;
    }

/*  // TC O(N**2) SC O(1)
    for (i = 2; i < n; i++) {
        // this loop will skip 1 and i
        // if i is divisible to any up to i-1, it is not a prime
        for (j = 2; j < i; j++) {
            if ((i % j) == 0)   // is i divisible to any number up to i-1?
                break;
        }
        if (j == i) {
            // i is not divible to any number up to j -> a prime.
            cnt++;
        }
    }
*/
    // TC O(N) SC O(N)
    //
    vector<bool> prime(n, true);

    // Remove numbers < n which are multiple of 2, 3, 4, ...
    // Remaining are prime.
    //
    for (i = 2; i*i < n; i++) {
        if (prime[i]) {
            for (j = i; j*i < n; j++) {
                prime[i*j] = false;
            }
        }
    }
    for (i = 2; i < n; i++) {
        if (prime[i]) {
            cnt++;
        }
    }
    return cnt;
}

int main() {

    cout << "Input: 10 --> " << countPrimes(10) << endl;
    cout << "Input: 0 --> " << countPrimes(0) << endl;
    cout << "Input: 1 --> " << countPrimes(1) << endl;
    cout << "Input: 100 --> " << countPrimes(100) << endl;

    return 0;
}

