class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        
        sort(intervals.begin(),intervals.end());

        vector<vector<int>> result;
        vector<int> newInterval=intervals[0];
        result.push_back(newInterval);

        for(auto it:intervals) {
            if(it[0]<=newInterval[1]) {
                newInterval[1]=max(newInterval[1],it[1]);

                result.back()[1]=newInterval[1];
            }
            else {
                newInterval=it;
                result.push_back(it);
            }
        }

        return result;
    }
};