// C++ program to print all 
// permutations with duplicates allowed 

#include <iostream> 
#include <vector>

using namespace std; 

/* Function to print permutations of Nums list. This function takes three parameters: 
    1. Nums list 
    2. Starting index of the Nums list 
    3. Ending index of the Nums list. 
*/

void permute(vector<int> nums, int l, int r) { 
	int i; 

	if (l == r) { 
        // print it
        for (auto i : nums) {
		    cout << i << " ";  // perm is done, print it 
        }
        cout << endl;
    }
	else
	{ 
		for (i = l; i <= r; i++) 
		{ 
			swap(nums[l], nums[i]); 
			permute(nums, l+1, r); 
			swap(nums[l], nums[i]); //backtrack 
		} 
	} 
} 

/* Driver program to test above functions */

int main() 
{ 
    vector<int> nums;
    int num;

    while (1) {
        cout << "Enter numbers separated by white space (0 to terminate): ";
        nums = {};
        while (cin >> num) { //enter any non-integer to end the loop!
            if (num == 0)
                break;
            cout << num << " ";
            nums.push_back(num);
        }
        if (nums.size() == 0)
            break;  // terminate loop

	    permute(nums, 0, nums.size()-1); 
    }
	return 0; 
} 



