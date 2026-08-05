class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        if(x<=3) return 1;
        int low=1;
        int high=x;
        while(low<=high) {
            int mid=low+(high-low)/2;
            long long temp=(long long)mid*(long long)mid;
            if(temp==x) {
                return mid;
            }
            else if(temp>x) {
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return high;
    }
};