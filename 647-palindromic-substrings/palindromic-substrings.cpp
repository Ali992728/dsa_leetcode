class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        if(n<=1) return 1;
        int cnt=1;
        for(int i=1;i<n;i++) {
            //consider odd palindrome
            int low=i;
            int high=i;
            while(low>=0 && high<n && s[low]==s[high]) {
                cnt++;
                low--;
                high++;
                if(low<0 || high>n-1) break;
            }
            

            //consider even palindrome
            low=i-1;
            high=i;
            while(low>=0 && high<n && s[low]==s[high]) {
                cnt++;
                low--;
                high++;
                if(low<0 || high>n-1) break;
            }
    
        }

        return cnt;

    }
};