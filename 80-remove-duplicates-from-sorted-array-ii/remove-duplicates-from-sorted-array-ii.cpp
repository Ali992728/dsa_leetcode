class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++) {
            mpp[nums[i]]++;
        }
        vector<int> v;
        for(auto it:mpp) {
            if(it.second>=2) {
                v.push_back(it.first);
                v.push_back(it.first);
            }
            else v.push_back(it.first);
        }
        for(int i=0;i<v.size();i++) {
            nums[i]=v[i];
        }
        return v.size();
    }
};