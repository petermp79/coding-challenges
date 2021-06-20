// C++ program to print all 
// permutations with duplicates allowed 

#include <iostream> 
#include <string>
#include <algorithm>

using namespace std; 

/*
void swap(char *x, char *y) 
{ 
	char temp; 
	temp = *x; 
	*x = *y; 
	*y = temp; 
} 
*/

/* Function to print permutations of string. This function takes three parameters: 
    1. String 
    2. Starting index of the string 
    3. Ending index of the string. 
*/

void permute(string a, int l, int r) 
{ 
	int i; 
	if (l == r) 
		cout << a << endl;  // perm is done, print it 
	else
	{ 
		for (i = l; i <= r; i++) 
		{ 
			swap(a[l], a[i]); 
			permute(a, l+1, r); 
			swap(a[l], a[i]); //backtrack 
		} 
	} 
} 

/* Driver program to test above functions */

int main() 
{ 
	string str; 
    while (1) {
        cout << "Enter a string (^c to quit): ";
        cin >> str;
	    permute(str, 0, str.length()-1); 
    }
	return 0; 
} 

// This is code is contributed by rathbhupendra 


