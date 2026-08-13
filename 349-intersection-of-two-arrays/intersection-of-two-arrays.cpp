class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> st_1;
        set<int> st_2;
        for(auto it:nums1) {
            st_1.insert(it);
        }
        for(auto it:nums2) {
            st_2.insert(it);
        }
        vector<int> ans;
        for(auto it:st_1) {
            if(st_2.find(it)!=st_2.end()) {
                ans.push_back(it);
            }
        }
        return ans;
    }
};