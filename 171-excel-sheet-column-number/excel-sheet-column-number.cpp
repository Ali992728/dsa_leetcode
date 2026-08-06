class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long ans=0;
        if(columnTitle.size()==1) return columnTitle[0]-'A'+1;
        for(int i=0;i<columnTitle.size();i++) {
            ans=(ans*26)+(columnTitle[i]-'A'+1);
        }
        return ans;
    }
};