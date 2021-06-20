/*

    LEETCODE# 17

    Given a string containing digits from 2-9 inclusive, return all possible letter combinations 
    that the number could represent. Return the answer in any order.

    A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 
    1 does not map to any letters.

*/

#include <iostream>
#include <vector>

using namespace std;

void compose(string digits, int curDigit, vector<string> map, string combo, vector<string> &result) {
    if (curDigit == digits.length()) {
        //cout << "result " << combo << endl;
        return result.push_back(combo);
    }
    
    // Get letters mapped to current digit
    string mapStr = map[digits[curDigit] - '0'];
    
    // For each letter in mapStr, recursively add letters from the next digit ...
    // e.g. ad, ae, af, ...
    for (auto i = 0; i < mapStr.length(); i++) {
        compose(digits, curDigit+1, map, combo+mapStr[i], result);
    }
    
}

int main() {
    vector<string> map {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    
    
    vector<string> result{};
    string combo = {};
    compose("23", 0, map, combo, result);
    for (auto x : result)
        cout << x << ", ";
    cout << endl;
    
    result = {};
    combo = {};
    compose("", 0, map, combo, result);
    for (auto x : result)
        cout << x << ", ";
    cout << endl;
    
    result = {};
    combo = {};
    compose("2", 0, map, combo, result);
    for (auto x : result)
        cout << x << ", ";
    cout << endl;
    
    return 0;
}



