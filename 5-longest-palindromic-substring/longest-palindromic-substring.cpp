class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n<=1) return s;
        string lps="";
        for(int i=1;i<n;i++) {
            //consider odd palindrome
            int low=i;
            int high=i;
            while(low>=0 && high<n && s[low]==s[high]) {
                low--;
                high++;
                if(low<0 || high>n-1) break;
            }
            string palindrome=s.substr(low+1,high-low-1);
            if(palindrome.size()>lps.size()) {
                lps=palindrome;
            }
            

            //consider even palindrome
            low=i-1;
            high=i;
            while(low>=0 && high<n && s[low]==s[high]) {
                low--;
                high++;
                if(low<0 || high>n-1) break;
            }
            palindrome=s.substr(low+1,high-low-1);
            if(palindrome.size()>lps.size()) {
                lps=palindrome;
            }
            
        }

        return lps;
    }
};