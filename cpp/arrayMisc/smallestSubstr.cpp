// C++ program to find the smallest
// window containing all characters
// of a pattern.

#include <iostream>
#include <unordered_map>

using namespace std;
 
const int MAX_CHARS = 256;
 
// Function to find smallest window containing
// all distinct characters
string findSubString(string str)
{
    int n = str.length();
 
    // Count all distinct characters.
    int dist_count = 0;
    unordered_map<int, int> hash_map;
    for (int i = 0; i < n; i++) {
        hash_map[str[i]]++;
    }
    dist_count = hash_map.size();

    cout << " (" << dist_count << ") ";

    // For each substring in string, find the shortest substring
    // that has all distinct chars (dist_count)

    int size = INT_MAX;
    string res;

    for (int i = 0; i < n; i++) {
        int count = 0;
        int visited[256] = { 0 };
        string sub_str = "";
        for (int j = i; j < n; j++) {
            if (visited[str[j]] == 0) {
                count++;
                visited[str[j]] = 1;
            }
            sub_str += str[j];
            if (count == dist_count)
                break;
        }
        if (sub_str.length() < size && count == dist_count)
        {
            // shorter than previous one
            res = sub_str;
            size=res.length();
        }
    }
    return res;
}
 
// Driver Code
int main()
{
    // string str = "aabcbcdbca";
    string str;

    while (1) {
        cout << "Enter a string (^c to quit): ";
        cin >> str;

        cout << "Smallest window containing all distinct"
                " characters is: "
            << findSubString(str) << endl;
    }
    return 0;
}

