class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        stringstream ss(path);
        string dirfile;
        while(getline(ss,dirfile,'/')) {
            if(!v.empty() && dirfile=="..") {
                v.pop_back();
            }
            else if(dirfile!="." && dirfile!=".." && dirfile!="") {
                v.push_back(dirfile);
            }
        }
        string ans="";
        for(auto it:v) {
            ans+='/'+it;
        }
        return ans.empty()? "/":ans;
    }
};