#include <iostream>
#include <string>
#include <vector>

using namespace std;

string multiply(string num1, string num2) {
    int l1 = num1.length();
    int l2 = num2.length();

    if (l1 == 0 || l2 == 0)
        return "0";
    
    vector<int> result(l1+l2, 0);
    int carry = 0;
    int c1 = 0;
    int c2 = 0;       
    
    cout << num1 << endl;
    cout << num2 << endl;
    
    for (int i = l1-1; i >= 0; i--) {
        int n1 = num1[i] - '0';
        carry = 0;
        
        c2 = 0;
        for (int j = l2-1; j >= 0; j--) {
            int n2 = num2[j] - '0';
                
            cout << n1 << "*" << n2 << "+" << result[c1+c2] << "+" << carry << endl;

            int sum = n1*n2 + result[c1+c2] + carry;
            carry = sum / 10;
            result[c1+c2] = sum % 10;
            c2++;
        }
        result[c1+c2] += carry;
        
        c1++;
    }
    //cout << "Get 1" << endl;
    
    int i = result.size()-1;
    while (i >= 0 && result[i] == 0) i--;
    
    if (i < 0) return "0";
    
    //cout << "Get 2" << endl;
    
    string resultStr = "";
    while (i >= 0) {
        cout << i << ". " << result[i] << endl;
        resultStr += to_string(result[i--]); 
    }
    
    return resultStr;
    
}


int main() {
    //string str1 = "1235421415454545454545454544"; 
    //string str2 = "1714546546546545454544548544544545"; 

    string str1 = "567";
    string str2 = "123";

    cout << ">>> Result: " << multiply(str1, str2) << endl;

    return 0;
}



