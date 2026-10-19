class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++) {
            int cnt=0;
            for(int j=31;j>=0;j--) {
                if((i>>j)&1 == 1) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};