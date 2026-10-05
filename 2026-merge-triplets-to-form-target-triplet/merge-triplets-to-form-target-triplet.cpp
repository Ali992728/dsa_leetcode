class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> v(3,0);
        for(auto it:triplets) {
            if(it[0]<=target[0] && it[1]<=target[1] && it[2]<=target[2]) {
                v[0]=max(v[0],it[0]);
                v[1]=max(v[1],it[1]);
                v[2]=max(v[2],it[2]);
            }
        }

        if(v==target) return true;
        else return false;
    }
};