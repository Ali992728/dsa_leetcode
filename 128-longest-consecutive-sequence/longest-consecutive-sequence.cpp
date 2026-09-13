class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        set<int> st;
        for(auto it:nums) {
            st.insert(it);
        }

        vector<int> v(st.begin(),st.end());

        int ans=1;
        int cnt=1;

        int i=1;
        while(i<v.size()) {
            if(v[i]==v[i-1]+1) {
                cnt++;
            }
            else {
                cnt=1;
            }
            i++;
            ans=max(ans,cnt);
        }
        return ans;
    }
};