class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> preS(n);
        preS[0]=nums[0];
        for(int i=1;i<n;i++) {
            preS[i]=nums[i]*preS[i-1];
        }

        vector<int> suffS(n);
        suffS[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--) {
            suffS[i]=nums[i]*suffS[i+1];
        }

        vector<int> ans(n);
        ans[0]=suffS[1];
        ans[n-1]=preS[n-2];

        for(int i=1;i<=n-2;i++) {
            ans[i]=preS[i-1]*suffS[i+1];
        }

        return ans;
    }
};