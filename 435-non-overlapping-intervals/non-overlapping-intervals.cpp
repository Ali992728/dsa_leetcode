class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<int> newInterval=intervals[0];
        int cnt=0;

        for(int i=1;i<n;i++) {
            if(intervals[i][0]<newInterval[1]) {
                cnt++;
                newInterval[1]=min(newInterval[1],intervals[i][1]);
            }
            else {
                newInterval[1]=intervals[i][1];
            }
        }

        return cnt;
    }
};