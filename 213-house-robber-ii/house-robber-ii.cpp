class Solution {
private:
    int robHelper(vector<int> &loot) {
        int n=loot.size();
        if(n<2) return loot[0];
        vector<int> dp(n);
        dp[0]=loot[0];
        dp[1]=max(loot[0],loot[1]);
        for(int i=2;i<n;i++) {
            dp[i]=max(dp[i-2]+loot[i] , dp[i-1]);
        }
        return *max_element(dp.begin(),dp.end());
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return nums[0];
        vector<int> skip_first(n-1);
        vector<int> skip_last(n-1);

        for(int i=0;i<n-1;i++) {
            skip_last[i]=nums[i];
            skip_first[i]=nums[i+1];
        }

        int lootSkippingFirst=robHelper(skip_first);
        int lootSkippingLast=robHelper(skip_last);

        return max(lootSkippingFirst,lootSkippingLast);
    }
};