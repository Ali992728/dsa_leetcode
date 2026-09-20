class Solution {
private:
    bool contains(map<char,int> &mapS,map<char,int> &mapT) {
        for(auto it:mapT) {
            if(it.second>mapS[it.first]) {
                return false;
            }
        }

        return true;
    }
public:
    string minWindow(string s, string t) {
        map<char,int> mapS;
        map<char,int> mapT;

        for(int i=0;i<t.size();i++) {
            mapT[t[i]]++;
        }

        int left=0,right=0;
        int minLength=INT_MAX;
        int minStart=0;

        for(;right<s.size();right++) {
            mapS[s[right]]++;

            while(contains(mapS,mapT)) {
                if(right-left+1 < minLength) {
                    minLength=right-left+1;
                    minStart=left;
                }
                mapS[s[left]]--;
                left++;
            }
        }

        if(minLength==INT_MAX) return "";

        return s.substr(minStart,minLength);
    }
};