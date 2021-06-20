//
//
// Longest substring without duplicate chars.
//
//

#include <iostream>
#include <array>

using namespace std;

// Use a lastSeen table to record the last index of chars observed
//
//  1/ Scan thru the string, left->right, looks for char that we have seen previously 
//  2/ If found a dup, reset starting index and check if last substring the longest 
//
int lengthOfLongestSubstring(string str) {
	array <int, 127> lastSeen{};	// printable chars assii code = 32-126
                                    // remember the str index of the char was seen
	int start = 0;
	int longest = 1;
    int slen = str.size();
    
    if (slen <= 1)
        return slen;
    
    // Init lastseen table with negative index, i.e. never seen
    // since index could be from 0 to slen-1
    //
	for (int i = 0; i < 127; i++) lastSeen[i] = -1;
	
	for (int i = 0; i < slen; i++) {
		int ch = str[i];
		
        // check if we have seen this arr[i] elem
		if (lastSeen[ch] >= 0)	{ 	
            // yes, it is a dup char
            longest = max(longest, i-start);    //  is this substring longer than a prev one
			start = max(start, lastSeen[ch]+1); // start over from the next char of lastseen char
		}
		lastSeen[ch] = i;	        // record where this char was seen
	}

    //  is the last substring longer than a prev one
	longest = max(longest, slen-start); 
    return longest;
}

int main()
{
    string str;

    cout << "Enter a string: ";

    cin >> str;

    cout << endl;

    cout << lengthOfLongestSubstring(str) << endl;
}



