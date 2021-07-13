/*

    Find number of subsets of a list of integers which sums up to K.

 */


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int subsetCount(vector<int> arr, int i, int k, int sum, unordered_map<string, int>& memo) {
    string key = to_string(i) + " " + to_string(sum);
    auto itr = memo.find(key);
    if (itr != memo.end()) {
        // This pattern was previously computed, return saved result
        return itr->second;
    }
    if (sum == k) 
        return 1;   // Got a match
    else if (sum > k || i >= arr.size()) 
        return 0;   // Ops! not match
    else {
        // Continue to process the next element in the arr 
        int subsets = subsetCount(arr, i+1, k, sum+arr[i+1], memo) + subsetCount(arr, i+1, k, sum, memo);
        // Save result so later we dont have to do this again
        // if encountered
        memo.insert(make_pair(key, subsets));
        return subsets;
    }
}

int subsetsThatSumUpToK(vector<int> arr, int k){
    // your code here
    unordered_map<string, int> memo;
    
    return subsetCount(arr, 0, k, 0, memo);
}

int main() {
    vector<int> arr{1, 2, 3 ,1};
    int k = 4;
    // expect 3
    cout << "Result: " << subsetsThatSumUpToK(arr, k) << endl;

    arr = {1, 1, 1 ,1};
    k = 1;
    // expect 4
    cout << "Result: " << subsetsThatSumUpToK(arr, k) << endl;

    arr = {1, 5, 2, 3, 1, 4, 6, 2, 1, 3, 7, 1, 2};
    k = 5;
    // expect 28
    cout << "Result: " << subsetsThatSumUpToK(arr, k) << endl;

    arr = {1, 5, 2, 3, 1, 4, 6, 2, 1, 3, 7, 1, 2};
    k = 15;
    // expect 416
    cout << "Result: " << subsetsThatSumUpToK(arr, k) << endl;

    arr = {1, 2, 3, 1, 5, 1, 8, 3, 6, 4, 2, 1, 0, 1, 4, 5, 6, 7, 2, 3, 4};
    k = 18;
    // expect 5386
    cout << "Result: " << subsetsThatSumUpToK(arr, k) << endl;

    return 0;
}



