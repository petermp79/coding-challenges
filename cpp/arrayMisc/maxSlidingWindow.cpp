//DeQue Solution
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //Pair<int,int> contains (nums[i],index)
        deque<pair<int,int>> dq;  //We will store elements in the deque only inside our current window
        vector<int> ans;
        
        for(int i=0;i<nums.size();++i)
        {
            if(!dq.empty() and dq.front().second<=(i-k))    //Remove front element if it goes out of window size
                dq.pop_front();
            while(!dq.empty() and dq.back().first<nums[i])  //Maintain elements in DSC order
                dq.pop_back();
            dq.push_back(make_pair(nums[i],i));     //Push current NODE
            if(i>=(k-1))
                ans.push_back(dq.front().first);    //Include maximum of cuurrent window
        }
        return ans;
    }
};



