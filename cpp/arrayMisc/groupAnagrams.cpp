/*

    LEETCODE# 49

    Given an array of strings strs, group the anagrams together. You can return the answer in any order.

    An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
    typically using all the original letters exactly once.

 
    Example 1:
    Input: strs = ["eat","tea","tan","ate","nat","bat"]
    Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

    Example 2:
    Input: strs = [""]
    Output: [[""]]

    Example 3:
    Input: strs = ["a"]
    Output: [["a"]]
 

    Constraints:
        1 <= strs.length <= 104
        0 <= strs[i].length <= 100
        strs[i] consists of lower-case English letters.

*/

#include <iostream>
#include <vector>

using namespace std;

static bool sortByString(const pair<int, string> &a, const pair<int, string> &b)
{
    return (a.second < b.second);
}
vector<vector<string>> groupAnagrams(vector<string> strs) {
    vector<vector<string>> result;
    vector<pair<int, string>> indexStrs;
    
    if (strs.size() == 0)
        return result;
    
    // 1/ Sort the content of every word and add an index to each of them
    //
    int index = 0;
    for (auto &s : strs) {
        string str(s);
        
        sort(str.begin(), str.end());
        indexStrs.push_back(make_pair(index, str));
        index++;
    }
    
    // 2/ Sort word list to group those similar together
    //
    sort(indexStrs.begin(), indexStrs.end(), sortByString);
    
    string prevStr{};
    vector<string> aGroup{};                // group of anagram strings
    bool firstRound = true;
    
    // 3/ Scan through sorted word list to pick out similar words
    //
    for (auto &str : indexStrs) {
        // cout << str.first << ":" << str.second << endl;
        //
        // str.first -> index of original word list
        // str.second -> original word
        //

        if (!firstRound) {                      // NOTE: input string could be "" so cant check
            string word = str.second;           //       prevStr for null
            
            if (prevStr.compare(word) != 0) {   // start of new group?
                
                // 5. Save current group to result list and start a new group
                
                result.push_back(aGroup);       // save prev group to result list
                aGroup.clear();                 // start new group
            }
        }
        else
            firstRound = false;
 
        
        // 4. Group anagram words together
        //
        //cout << strs[str.first] << endl;
        int index = str.first;
        aGroup.push_back(strs[index]);   // add original word to group using index
        prevStr = str.second;
    }
    result.push_back(aGroup);    // last group
    
    return result;
}

void printSubsets(string heading, vector<vector<string>> subsets) {

    cout << heading << "[ ";
    for (auto subset : subsets) {
        cout << "[";
        for (auto x : subset) {
            if (x.length() == 0)
                cout << "\"\"" << ",";
            else
                cout << x << ",";
        }
        cout << "], ";
    }
    cout << "]" << endl;
}

int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result;
 
    result = groupAnagrams(strs);
    printSubsets("['eat','tea','tan','ate','nat','bat'] --> ", result);

    result = groupAnagrams({""});
    printSubsets("[''] --> ", result);

    result = groupAnagrams({"a"});
    printSubsets("['a'] --> ", result);

    return 0;
}


