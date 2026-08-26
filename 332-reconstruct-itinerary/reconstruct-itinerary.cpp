class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> adj;
        for(int i=0;i<tickets.size();i++) {
            adj[tickets[i][0]].insert(tickets[i][1]);
        }

        vector<string> ans;
        stack<string> st;

        st.push("JFK");

        while(!st.empty()) {
            string src=st.top();
            if(adj[src].size()==0) {
                st.pop();
                ans.push_back(src);
            }
            else {
                auto it=adj[src].begin();
                st.push(*it);
                adj[src].erase(it);
            }
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};