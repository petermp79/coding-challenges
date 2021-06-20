/*

    LEETCODE# 680

    Given a string s, return true if the s can be palindrome after deleting at most one character from it.

    Example 1:

    Input: s = "aba"
    Output: true

    Example 2:

    Input: s = "abca"
    Output: true
    Explanation: You could delete the character 'c'.

    Example 3:

    Input: s = "abc"
    Output: false
 

    Constraints:

        1 <= s.length <= 105
        s consists of lowercase English letters.

*/

#include <iostream>

using namespace std;

//
// Use two pointers: left and right
// 
bool validPalindrome(string s) {
    int len = s.size();
    int left = 0;
    int right = len - 1;
    
    if (len < 2)
        return true;
    
    // Traverse string from both ends until mis-match is detected
    for (; left < right; left++, right--) {
        if (s[left] != s[right]) {
            break;
        }
    }
    
    // skip mis-match char on the left
    int i = left+1;
    int j = right;
    while (i < j) {
        if (s[i] != s[j])
            break;
        i++;
        j--;
    }
    
    // If left and right meets without further mismatch, char to delete is on the left
    if (i >= j) {
        return true;
    }
    
    // skip mis-match char on the right
    i = left;
    j = right-1;
    while (i < j) {
        if (s[i] != s[j])
            break;
        i++;
        j--;
    }
    // If left and right meets without further mismatch, char to delete is on the right
    if (i >= j) {
        return true;
    }       
    
    return false;
}

int main() {

    cout << "Input: 'aba' --> " << validPalindrome("aba") << endl;
    cout << "Input: 'abca' --> " << validPalindrome("abca") << endl;
    cout << "Input: 'abc' --> " << validPalindrome("abc") << endl;
    cout << "Input: 'racecar' --> " << validPalindrome("racecar") << endl;

    return 0;
}


