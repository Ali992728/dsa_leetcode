class Solution {
private:
    bool isCycleDFS(int src,vector<bool> &vis,vector<bool> &recPath,vector<vector<int>> &prerequisites) {
        vis[src]=true;
        recPath[src]=true;

        for(int i=0;i<prerequisites.size();i++) {
            int v=prerequisites[i][0];
            int u=prerequisites[i][1];

            if(src==u) {
                if(!vis[v]) {
                    if(isCycleDFS(v,vis,recPath,prerequisites)) {
                        return true;
                    }
                }
                else if(recPath[v]) {
                    return true;
                }
            }
        }
        recPath[src]=false;
        return false;
    }

    void topoOrder(int src,vector<bool> &vis,stack<int> &st,vector<vector<int>> &prerequisites) {
        vis[src]=true;

        for(int i=0;i<prerequisites.size();i++) {
            int v=prerequisites[i][0];
            int u=prerequisites[i][1];

            if(src==u) {
                if(!vis[v]) {
                    topoOrder(v,vis,st,prerequisites);
                }
            }
        }

        st.push(src);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses,false);
        vector<bool> recPath(numCourses,false);
        vector<int> ans;

        for(int i=0;i<numCourses;i++) {
            if(!vis[i]) {
                if(isCycleDFS(i,vis,recPath,prerequisites)) {
                    return ans;
                }
            }
        }

        stack<int> st;
        vis.assign(numCourses,false);

        for(int i=0;i<numCourses;i++) {
            if(!vis[i]) {
                topoOrder(i,vis,st,prerequisites);
            }
        }

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};