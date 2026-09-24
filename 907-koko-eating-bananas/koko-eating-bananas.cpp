class Solution {
private:
    long long calculateHour(vector<int> &piles,int hour) {
        long long res=0;
        for(int i=0;i<piles.size();i++) {
            res+=ceil((double)piles[i]/(double)hour);
        }
        return res;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());

        while(low<=high) {
            int mid=(low+high)/2;
            long long hours_needed=calculateHour(piles,mid);

            if(hours_needed<=h) {
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return low;
    }
};