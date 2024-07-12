class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       if (strs.empty())
            return "";
        int n = strs.size();
        int i = 0;
        while (i < strs[0].size())
        {
            for (int j = 1; j < n; j++)
            {
                if (i >= strs[j].size() || strs[j][i] != strs[0][i])
                    return strs[0].substr(0, i);
            }
            i++;
        }
        return strs[0].substr(0, i); 
    }
};