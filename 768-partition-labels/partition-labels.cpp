class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;

        for (int i = 0; i < s.length(); ) {

            int start = i;
            int end = s.rfind(s[start]);

            for (int j = start + 1; j <= end - 1; j++) {

                int last = s.rfind(s[j]);

                if (last > end) {
                    end = last;
                }
            }

            ans.push_back(end - start + 1);

            i = end + 1;
        }

        return ans;
    }
};