class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        multiset<int> S;
        S.insert(nums[0]);
        int ans=0;

        for(int i=0,j=0;i<n and j<n;) {
            int mn=*(S.begin());
            int mx=*(S.rbegin());
            if(mx-mn<=k) {
                ans=max(ans,j-i+1);
                j++;
                if(j<n) S.insert(nums[j]);
            }
            else {
                auto it=S.find(nums[i]);
                S.erase(it);
                i++;
            }
        }

        return ans;
    }
};
