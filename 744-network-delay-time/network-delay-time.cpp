class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++) {
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];

            adj[u].push_back({v,w});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        vector<int> dist(n+1,INT_MAX);

        dist[k]=0;

        pq.push({0,k});

        while(!pq.empty()) {
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto it:adj[node]) {
                int edgeWeight=it.second;
                int adjNode=it.first;
                if(dis+edgeWeight < dist[adjNode]) {
                    dist[adjNode]=dis+edgeWeight;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }

        int ans=INT_MIN;
        for(int i=1;i<=n;i++) {
            ans=max(ans,dist[i]);
        }

        return ans==INT_MAX? -1:ans;
    }
};