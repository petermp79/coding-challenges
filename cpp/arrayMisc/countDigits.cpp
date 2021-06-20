//
//  Given an array nums of integers, return how many of them contain an even number of digits.
//

int findNumbers(vector<int>& nums) {
    int cnt = 0;
        
    for (int n : nums) {
        int digits = floor(log10(n)) + 1;
            
        if ((digits % 2) == 0) {
            cnt++;
        }
    }
    return cnt;
}
