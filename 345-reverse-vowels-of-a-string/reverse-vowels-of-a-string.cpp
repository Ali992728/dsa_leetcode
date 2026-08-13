class Solution {
private:
    bool isVowel(char c) {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U') {
            return true;
        }
        return false;
    }
public:
    string reverseVowels(string s) {
        vector<char> v;
        for(int i=0;i<s.size();i++) {
            if(isVowel(s[i])) {
                v.push_back(s[i]);
            }
        }

        int f=0;

        for(int i=s.size()-1;i>=0;i--) {
            if(isVowel(s[i])) {
                s[i]=v[f];
                f++;
            }
        }
        return s;
    }
};