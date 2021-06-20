/*

    LEETCODE# 14

    Write a function to find the longest common prefix string amongst an array of strings.

    If there is no common prefix, return an empty string "".

    Example 1:

        Input: strs = ["flower","flow","flight"]
        Output: "fl"

    Example 2:

        Input: strs = ["dog","racecar","car"]
        Output: ""
        Explanation: There is no common prefix among the input strings.
 

    Constraints:
        1 <= strs.length <= 200
        0 <= strs[i].length <= 200
        strs[i] consists of only lower-case English letters.
*/

#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> strs) {
    int prefixLen = INT_MAX;
    
    if (strs.size() == 0) 
        return "";
    
    // For every strings other than the first string
    for (int i = 1; i < strs.size(); i++) {
        string s = strs[i];
        
        // Find common prefix of the string against the first string
        // record the least length of common prefix
        for (int j = 0; j <= s.length(); j++) {
            if (j == s.length() || s[j] != strs[0][j]) {
                // Update max common prefix len if it is shorter
                prefixLen = min(prefixLen, j);
                break;
            }
        }
    }
    if (prefixLen == 0)
        return "";
    else {
        //cout << prefixLen << endl;
        return strs[0].substr(0, prefixLen);
    }
}

int main() {

    cout << "['flower', 'flight', 'flow']: " << longestCommonPrefix({"flower", "flight", "flow"}) << endl;
    cout << "['dog', 'racecar', 'car']: " << longestCommonPrefix({"dog", "racecar", "car"}) << endl;
}



