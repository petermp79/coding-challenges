/*
   Given a string, return all possible subsequences of the string.
   The order of the subsequences are not matter.

   TC: O(n*(2**n)) SC: O(n*(2**n))

*/

#include <iostream>
#include <vector>


using namespace std;

void recSubsequence(string str, int index, string subseq, vector<string>& result) {
    if (index == (int)str.length())
        result.push_back(subseq);
    else {
        recSubsequence(str, index+1, subseq, result);
        recSubsequence(str, index+1, subseq+str[index], result);
    }
}
vector<string> getSubsequences(string str){
    // your code here
    vector<string> result{};
    string subseq{};
    
    recSubsequence(str, 0, subseq, result);
    return result;
}

int main() {
    
    vector<string> result;
    string str;

    while (1) {
        cout << "Enter a string or q to quit: ";
        cin >> str;

        if (str == "q")
            break;

        result = getSubsequences(str);

        int i = 0;
        for (string subSeq : result) {
            i++;
            if (subSeq.length() == 0) 
                subSeq = "-";
            cout << subSeq << ", ";
        } 
        cout << endl;
        cout << i << " subsequences" << endl;
    }
}



