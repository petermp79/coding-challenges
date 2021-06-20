/*

    LEETCODE# 125

    Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

    Example 1:

    Input: s = "A man, a plan, a canal: Panama"
    Output: true
    Explanation: "amanaplanacanalpanama" is a palindrome.

    Example 2:

    Input: s = "race a car"
    Output: false
    Explanation: "raceacar" is not a palindrome.
 

    Constraints:

        1 <= s.length <= 2 * 105
        s consists only of printable ASCII characters.



*/

#include <iostream>

using namespace std;

bool isPalindrome(string s) {
    int len = s.length();
    string dup;
    
    if (len == 0)
        return false;
    else if (len == 1)
        return true;
    
    //cout << s << endl;
    
    // First, copy only alphanumric chars to another string 
    for (int i = 0; i < len; i++) {
        if (isalpha(s[i]) || isdigit(s[i]))
            dup += tolower(s[i]);
    }
    
    //cout << dup << endl;
    
    // Second, use left and right indices to find difference
    len = dup.length();
    for (int i = 0, j = len-1; i < j; i++, j--) {
        if (dup[i] != dup[j]) {
            //cout << i << ":" << j << "-" << dup[i] << ":" << dup[j] << endl;
            return false;
        }
    }
    return true;
}


int main() {
    cout << "Input: 'A man, a plan, a canal: Panama' --> " << isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << "Input: 'race a car' --> " << isPalindrome("race a car") << endl;

    return 0;    
}


