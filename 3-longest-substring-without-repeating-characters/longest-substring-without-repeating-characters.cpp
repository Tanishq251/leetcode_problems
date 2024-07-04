class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        int maxLength = 0;
        int start = 0;

        for (int end = 0; end < n; end++) {
            if (mp.find(s[end]) != mp.end()) {
                start = max(start, mp[s[end]] + 1);
            }
            mp[s[end]] = end;
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};
