class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int> freq1;
        map<char,int> freq2;

        for(int i=0;i<s1.size();i++) {
            freq1[s1[i]]++;
        }

        int l=0;

        for(int r=0;r<s2.size();r++) {
            freq2[s2[r]]++;

            int windowLength=r-l+1;

            if(windowLength > s1.size()) {
                freq2[s2[l]]--;
                if(freq2[s2[l]]==0) {
                    freq2.erase(s2[l]);
                }
                l++;
                windowLength=r-l+1;
            }

            if(windowLength==s1.size() && freq1==freq2) {
                return true;
            }
        }
        return false;
    }
};