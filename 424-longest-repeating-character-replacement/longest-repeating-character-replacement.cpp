class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> freq;
        int l=0;
        int maxWindow=0;
        int maxFreq=0;

        for(int r=0;r<s.size();r++) {
            freq[s[r]]++;

            int windowLength=r-l+1;

            maxFreq=max(maxFreq,freq[s[r]]);

            if(windowLength-maxFreq > k) {
                freq[s[l]]--;
                l++;
                windowLength=r-l+1;
            }

            maxWindow=max(maxWindow,windowLength);
        }
        return maxWindow;
    }
};