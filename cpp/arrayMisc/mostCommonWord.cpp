/*

    LEETCODE# 819

    Given a string paragraph and a string array of the banned words banned, return the most frequent word 
    that is not banned. It is guaranteed there is at least one word that is not banned, and that the 
    answer is unique.

    The words in paragraph are case-insensitive and the answer should be returned in lowercase.

 

    Example 1:

    Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
    Output: "ball"
    Explanation: 
        "hit" occurs 3 times, but it is a banned word.
        "ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
        Note that words in the paragraph are not case sensitive,
        that punctuation is ignored (even if adjacent to words, such as "ball,"), 
        and that "hit" isn't the answer even though it occurs more because it is banned.

    Example 2:

    Input: paragraph = "a.", banned = []
    Output: "a"
 

    Constraints:

        1 <= paragraph.length <= 1000
            paragraph consists of English letters, space ' ', or one of the symbols: "!?',;.".
        0 <= banned.length <= 100
        1 <= banned[i].length <= 10
            banned[i] consists of only lowercase English letters.



*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

// Use a words hash table (unordered map) to track word occurance and count
// And a hash table for storing banned words
// Check for banned before inserting to words hash table.
// Iterate words hash table to find the most used word

string mostCommonWord(string paragraph, vector<string> banned) {
    unordered_map<string, int> words;   // hash table of <words, #occurance> in text
    unordered_set<string> bWords;       // hash table of banned words
    
    // 1. Copy banned words to hash table
    for (auto w : banned) {
        bWords.insert(w);
    }
    
    // 2. Remove punctuation from paragraph and convert upper to lower chars
    for (int i = 0; i < paragraph.length(); i++) {
        if (isupper(paragraph[i])) 
                paragraph[i] = tolower(paragraph[i]);
        else if (ispunct(paragraph[i]))
                paragraph[i] = ' ';
    }
    //cout << paragraph << endl;
    
    // 3. Parse for words from paragraph and insert them to hash table with count of occurances
    istringstream ss(paragraph);
    string word;
    while (ss >> word) {
        // insert word to hash table and keep track of #occurance
        auto itr = words.find(word);
        if (itr != words.end()) {
            // Already inserted, update count of occurances
            ++itr->second;
        } else {
            // Now, check if this word is banned
            auto itr = bWords.find(word);
            if (itr == bWords.end())    // is banned?
                words.insert(make_pair(word, 1));   // Nope, insert to hash table
        }
    }
    
    // 4. Find the most occurance words
    int maxOccurance = 0;
    for (auto w : words) {
        if (w.second > maxOccurance) {
            word = w.first;
            maxOccurance = w.second;
        }
        
    }
    return word;
}

int main() {

    cout << "Paragraph: 'Bob hit a ball, the hit BALL flew far after it was hit'. Banned word: 'hit'" 
         << " --> " << mostCommonWord("Bob hit a ball, the hit BALL flew far after it was hit.", {"hit"}) << endl;

    cout << "Paragraph: 'a.'. Banned word: ''" 
         << " --> " << mostCommonWord("a.", {}) << endl;
}


