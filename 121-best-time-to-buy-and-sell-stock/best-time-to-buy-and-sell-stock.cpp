class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> lmin(n,0);
        lmin[0]=prices[0];
        for(int i=1;i<n;i++) {
            lmin[i]=min(lmin[i-1],prices[i]);
        }

        int ans=INT_MIN;

        for(int i=0;i<n;i++) {
            ans=max(ans,prices[i]-lmin[i]);
        }

        return ans;
    }
};