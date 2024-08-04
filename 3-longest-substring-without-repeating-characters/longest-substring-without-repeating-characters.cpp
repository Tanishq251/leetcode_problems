class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n  = s.size();

        unordered_map<char, int> mp;

        int maxs = 0;
        int start =0;

        for(int end =0; end<n; end++){
            if(mp.find(s[end]) != mp.end()){
                start = max(start,mp[s[end]]+1);
            }
            mp[s[end]] = end;
            maxs = max(maxs, end-start+1);
        }

        return maxs;
    }
};