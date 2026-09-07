class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,k=0;
        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                if(nums[i]+nums[j] == target) {
                    l=i;
                    k=j;
                    break;
                }
            }
            if(l!=0 && k!=0) break;
        }
        return {l,k};
    }
};