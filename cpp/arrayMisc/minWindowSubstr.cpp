/*
    LEETCODE# 76

    Given two strings s and t of lengths m and n respectively, return the minimum window substring 
    of s such that every character in t (including duplicates) is included in the window. 
    If there is no such substring, return the empty string "".

    The testcases will be generated such that the answer is unique.

    A substring is a contiguous sequence of characters within the string.

 
    Example 1:

    Input: s = "ADOBECODEBANC", t = "ABC"
    Output: "BANC"
    Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

    Example 2:

    Input: s = "a", t = "a"
    Output: "a"
    Explanation: The entire string s is the minimum window.

    Example 3:

    Input: s = "a", t = "aa"
    Output: ""
    Explanation: Both 'a's from t must be included in the window.
    Since the largest window of s only has one 'a', return empty string.
 

    Constraints:
        m == s.length
        n == t.length
        1 <= m, n <= 105
        s and t consist of uppercase and lowercase English letters.

*/

#include <iostream>
#include <vector>

using namespace std;

// String t could have repetion of chars and thefore, could be very long.
// Characters in either string could be upper case or lower case.
//
// Use a unordered_map<char, int> (hash) to store chars in t to optimize space.
// char is used as the hash key and int is to count the repetition of char in string t. 
// Use an int as counter to quickly check when all chars in t are matched. 
//
string minWindow(string s, string t) {
    string minStr;                  // keep track of minimun string         
    vector<int> tTable(128, INT_MIN); // record chars in string t with repetition cover a-z/A-Z
    int tlen = t.length();
    int slen = s.length();
    int cnt = 0;                    // number of distinct chars
    
    //cout << "s: " << s << endl;
    //cout << "t: " << t << endl;
    
    if (slen == 0 || slen < tlen) 
        return "";              // no match
    
    if (tlen == 0) {
        return s;               // no matching need to be done
    }
    
    // 1. Conver t string into a table recording chars in string t and their repetition
    //    Location 0 of table records the tlen
    //
    tTable[0] = tlen;
    for (int i = 0; i < tlen; i++) {
        if (tTable[t[i]] == INT_MIN) {
            tTable[t[i]] = 1;
            cnt++;              // number of distinct chars
        }
        else
            tTable[t[i]]++;     // same char could occur more than once 
    }
 

    // 2. Use left and right pointers to scan for match of condition
    //    Move right pointer until the condition is met, then move left until the 
    //    condition is unmet.
    //
    // 3. Record the min length of matching substring limited by left and right
    //
    int left = 0;
    int right = 0;
    
    for (int right = 0; right < slen; right++) {
        char ch = s[right];

        if (tTable[ch] == INT_MIN)
            continue;
        
        tTable[ch]--;
        if (tTable[ch] == 0)
            cnt--;
            
        if (cnt == 0) {  // All found?
            // Move left pointer till condition is unmet
            while (cnt == 0) {
                char ch = s[left++];
                if (tTable[ch] == 0) {
                    cnt++;
                }
                tTable[ch]++;
            }       
            // Yes, record the shortest so far
            int subStrLen = right - left + 2;
            if (minStr.length() == 0 || minStr.length() > subStrLen) {
                minStr = s.substr(left-1, subStrLen);
            }
        }
    }
    return minStr;
}

int main() {
    cout << "s='ADOBECODEBANC', t='ABC' --> " << minWindow("ADOBECODEBANC", "ABC") << endl; 
    cout << "s='a', t='a' --> " << minWindow("a", "a") << endl; 
    cout << "s='a', t='aa' --> " << minWindow("a", "aa") << endl; 

    return 0;
}


