class Solution {
private:
    int manDist(vector<vector<int>> &points,int p1,int p2) {
        return abs(points[p1][0]-points[p2][0]) + abs(points[p1][1]-points[p2][1]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        vector<bool> mstSet(n,false);

        int mstCost=0;

        pq.push({0,0});

        while(!pq.empty()) {
            int node=pq.top().second;
            int wt=pq.top().first;
            pq.pop();

            if(mstSet[node]) continue;

            mstSet[node]=true;
            mstCost+=wt;
            for(int i=0;i<n;i++) {
                if(!mstSet[i]) {
                    pq.push({manDist(points,node,i),i});
                }
            }
        }
        return mstCost;
    }
};