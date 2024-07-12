class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = n-1;
        while (i >= 0 && s[i] == ' ') i--;
        int j = 0;
        while (i >= 0 && s[i] != ' ') i--, j++;
        return j;
    }
};