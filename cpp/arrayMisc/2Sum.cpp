/*

   LEETCODE #1 - Two Sum

   Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

   For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

   Bonus: Can you do this in one pass?

*/


#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> findTwo(vector<int> list, int k) {
    unordered_set<int> hashmap{};

    for (auto i : list) {
        // lookup hash table to see if it is the difference of 
        // a previous element
        //
        auto itr = hashmap.find(i);
        if (itr != hashmap.end()) {
            // yes, it is we found a 2sum, previous elem and this one.
            return {i, k - i};
        }
        // store the difference in the hash table for later lookup
        hashmap.insert(k-i);
    }
    return {};
    
}


int main() {
    vector<int> list = { 4, 3, 5, 7, 9, 1, 6, 8 };
    
    auto two = findTwo(list, 12);

    cout << "Result: ";
    for (auto n : two) {
        cout << n << ", ";
    }  
    cout << endl;
}


