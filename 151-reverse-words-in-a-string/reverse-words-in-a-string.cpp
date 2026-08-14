class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        int i=0;
        int j=s.size();
        while(s[i]==' ') i++;
        while(s[j]==' ') j--;

        while(i<j) {
            if(s[i]!=' ') {
                string f="";
                while(i<j && s[i]!=' ') {
                    f+=s[i];
                    i++;
                }
                v.push_back(f);
            }
            else {
                while(i<j && s[i]==' ') {
                    i++;
                }
            }
        }
        string ans="";
        for(int i=v.size()-1;i>=0;i--) {
            ans+=v[i];
            if(i!=0) ans+=' ';
        }
        return ans;
    }
};