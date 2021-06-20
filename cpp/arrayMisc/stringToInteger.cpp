/*

    LEETCODE# 8

    Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer 
    (similar to C/C++'s atoi function).

    The algorithm for myAtoi(string s) is as follows:

    Read in and ignore any leading whitespace.
    Check if the next character (if not already at the end of the string) is '-' or '+'. 
    Read this character in if it is either. This determines if the final result is negative or 
        positive respectively. Assume the result is positive if neither is present.
    Read in next the characters until the next non-digit charcter or the end of the input is 
        reached. The rest of the string is ignored.
    Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were 
        read, then the integer is 0. Change the sign as necessary (from step 2).
    If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the 
        integer so that it remains in the range. Specifically, integers less than -231 should be 
        clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
    Return the integer as the final result.

    Note:
    -----
    Only the space character ' ' is considered a whitespace character.
    Do not ignore any characters other than the leading whitespace or the rest of the string 
        after the digits.
 

    Example 1:

    Input: s = "42"
    Output: 42

    Explanation: The underlined characters are what is read in, the caret is the current reader position.
        Step 1: "42" (no characters read because there is no leading whitespace)
                 ^
        Step 2: "42" (no characters read because there is neither a '-' nor '+')
                 ^
        Step 3: "42" ("42" is read in)
                   ^
        The parsed integer is 42.
        Since 42 is in the range [-231, 231 - 1], the final result is 42.

    Example 2:

    Input: s = "   -42"
    Output: -42
    Explanation:
        Step 1: "   -42" (leading whitespace is read and ignored)
                    ^
        Step 2: "   -42" ('-' is read, so the result should be negative)
                     ^
        Step 3: "   -42" ("42" is read in)
                       ^
            The parsed integer is -42.
            Since -42 is in the range [-231, 231 - 1], the final result is -42.

    Example 3:

    Input: s = "4193 with words"
    Output: 4193
    Explanation:
        Step 1: "4193 with words" (no characters read because there is no leading whitespace)
                 ^
        Step 2: "4193 with words" (no characters read because there is neither a '-' nor '+')
                 ^
        Step 3: "4193 with words" ("4193" is read in; reading stops the next character is a non-digit)
                     ^
        The parsed integer is 4193.
        Since 4193 is in the range [-231, 231 - 1], the final result is 4193.

    Example 4:

    Input: s = "words and 987"
    Output: 0
    Explanation:
        Step 1: "words and 987" (no characters read because there is no leading whitespace)
         ^
        Step 2: "words and 987" (no characters read because there is neither a '-' nor '+')
         ^
        Step 3: "words and 987" (reading stops immediately because there is a non-digit 'w')
         ^
        The parsed integer is 0 because no digits were read.
        Since 0 is in the range [-231, 231 - 1], the final result is 0.

    Example 5:

    Input: s = "-91283472332"
    Output: -2147483648
    Explanation:
        Step 1: "-91283472332" (no characters read because there is no leading whitespace)
                 ^
        Step 2: "-91283472332" ('-' is read, so the result should be negative)
                  ^
        Step 3: "-91283472332" ("91283472332" is read in)
                             ^
        The parsed integer is -91283472332.
        Since -91283472332 is less than the lower bound of the range [-2**31, 2**31 - 1], 
            the final result is clamped to -231 = -2147483648.
 

Constraints:

    0 <= s.length <= 200
    s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.

*/

#include <iostream>

using namespace std;

int myAtoi(string s) {
    int i = 0;
    bool negative = false;
    long n = 0;

    while (i < s.size()) {
        if (s[i] == ' ') {  // 1. skip white spaces
            i++;
            continue;
        }
        else if (s[i] == '-') {  // 2. track sign +/-
            negative = true;
            i++;
            if (isdigit(s[i]))
                continue;
            else
                return 0;   // no digit followed sign, bad
        }
        else if (s[i] == '+') {  
            negative = false;
            i++;
            if (isdigit(s[i]))
                continue;
            else
                return 0;   // no digit followed sign, bad
        }
        else if (!isdigit(s[i])) {   // no digit in first char, bad
            return 0;
        }
        else {
            int start = i;      // start of digit string
            int end = 0;        // determine where it ends
    
            //cout << "digit " << s[i] << endl;
            
            while (i < s.size()) {      // 3. skip to end of digits
                if (isdigit(s[i]))
                    i++;
                else 
                    break;
            }
            end = i;
            
            // 4. convert the number
               
            i = start;
            for (int i = start; i < end; i++) {   // convert digits from start to end
                
                int digit = s[i] - '0';
                n = (n*10) + digit;
                if (n > INT_MAX)    // if number exceeds range, quit
                    break;
                
            }
            // 4. Apply sign 
            if (negative) {
                n = -n;
            }
            
            if (n < INT_MIN) 
                n = INT_MIN;
            else if (n >= INT_MAX)
                n = INT_MAX;
        }
        break;
    }
    return (int)n;
}

int main() {

    cout << "myAtoi(42): " << myAtoi("42") << endl;     
    cout << "myAtoi(-42): " << myAtoi("-42") << endl;     
    cout << "myAtoi(4193 with words): " << myAtoi("4193 with words") << endl;     
    cout << "myAtoi(words and 987): " << myAtoi("words and 987") << endl;     
    cout << "myAtoi(-91283472332): " << myAtoi("-91283472332") << endl;     

    cout << "myAtoi(''): " << myAtoi("") << endl;;
    cout << "myAtoi('1234567890'): " << myAtoi("  1234567890") << endl;;
    cout << "myAtoi('+1234567890'): " << myAtoi(" +1234567890") << endl;;
    cout << "myAtoi('-1234567890'): " << myAtoi(" -1234567890") << endl;;
    cout << "myAtoi('+-1234567890'): " << myAtoi("+-1234567890") << endl;;
    cout << "myAtoi('12345 67890'): " << myAtoi("+-12345 67890") << endl;;
    cout << "myAtoi('+ 1234567890'): " << myAtoi("+ 1234567890") << endl;;
    cout << "myAtoi('1234567890 + -'): " << myAtoi("1234567890 + -") << endl;;

}

