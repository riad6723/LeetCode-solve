class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), cnt = 0, ans = INT_MAX;
        vector<int> preSum(2*n+10);

        for(int i=0;i<n;i++) {
            nums.push_back(nums[i]);
            if(nums[i] == 1) cnt++;
        }

        for(int i=0;i<2*n;i++) preSum[i+1] = preSum[i] + nums[i];

        for(int i=0;i<n;i++) {
            int l = i;
            int r = l + cnt -1;
            int ones = preSum[r+1] - preSum[l];
            ans = min(ans, cnt - ones);
        }

        return ans;
    }
};
