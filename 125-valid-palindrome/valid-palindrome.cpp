class Solution {
public:
    bool isPalindrome(string s) {
        string f="";
        for(int i=0;i<s.size();i++) {
            if((s[i]<='z' && s[i]>='a') || (s[i]<='Z' && s[i]>='A') || (s[i]<='9' && s[i]>='0')) {
                f+=tolower(s[i]);
            }
        }

        string revf=f;
        reverse(revf.begin(),revf.end());

        if(f==revf) return true;
        else return false;
    }
};