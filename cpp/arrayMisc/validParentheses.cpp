/*
    LEETCODE# 20

    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
 

    Example 1:

    Input: s = "()"
    Output: true

    Example 2:

    Input: s = "()[]{}"
    Output: true

    Example 3:

    Input: s = "(]"
    Output: false

    Example 4:

    Input: s = "([)]"
    Output: false

    Example 5:

    Input: s = "{[]}"
    Output: true
 

    Constraints:

        1 <= s.length <= 104
        s consists of parentheses only '()[]{}'.

*/

#include <iostream>

using namespace std;

bool isValid(string s) {
    int top = -1;

    char *stack = new char[s.length()]{};
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '('  || s[i] == '[' || s[i] == '{') {
            // Add to stack
            stack[++top] = s[i];
        }
        else if (top >= 0 && s[i] == ')' && stack[top] == '(') {
            top--;
        }
        else if (top >= 0 && s[i] == ']' && stack[top] == '[') {
            top--;
        }
        else if (top >= 0 && s[i] == '}' && stack[top] == '{') {
            top--;
        }
        else
            return false;   // we have more close brackets than open
    }
    
    return top == -1 ? true : false;    // empty
}

int main() {
    
    cout << "(()[}]) -->" << isValid("(()[}])") << endl;
    
    cout << "(()[]) -->" << isValid("(()[])") << endl;
    
    cout << "(()[]{)} -->" << isValid("(()[]{)}") << endl;

    cout << "(()[]{}) -->" << isValid("(()[]{})") << endl;
    
    cout << "(()())) -->" << isValid("(()()))") << endl;

    cout << "(()()) -->" << isValid("(()())") << endl;

    cout << " -->" << isValid("") << endl;
}


