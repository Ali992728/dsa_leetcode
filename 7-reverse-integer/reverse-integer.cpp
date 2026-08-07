class Solution {
public:
    int reverse(int x) {
        string s=to_string(x);
        string ans="";
        int i=s.size()-1;
        while(i>=0 && s[i]=='0') {
            i--;
        }
        for(i;i>=0;i--) {
            if(s[i]!='-') {
                ans+=s[i];
            }
        }
        if(s[0]=='-') ans="-"+ans;
        if(ans=="") return 0;
        long long fin=stoll(ans);
        return (fin>INT_MAX || fin<INT_MIN)? 0:fin;
    }
};