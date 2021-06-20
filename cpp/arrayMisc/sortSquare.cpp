//
// Given an integer array nums sorted in non-decreasing order, return an array of the squares of 
// each number sorted in non-decreasing order.
//
//

vector<int> sortedSquares(vector<int>& nums) {
    int left = 0;
    int right = nums.size()-1;
    vector<int> result{};
    //cout << left << ":" << right << endl;
    
    while (left <= right) {
        cout << left << ":" << right << endl;
        if (abs(nums[left]) > abs(nums[right])) {
            int n = nums[left];
            result.push_back(n * n);
            left++;
        } else {
            int n = nums[right];
            result.push_back(n * n);
            right--;
        }
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}


