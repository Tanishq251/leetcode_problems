class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int n = s.size();
        int i = 0;
        
        while (i < n) {
            while (i < n && s[i] == ' ') 
                i++;
            if (i < n) {
                int j = i + 1;
                while (j < n && s[j] != ' ')
                    j++;
                words.push_back(s.substr(i, j - i));
                i = j + 1;
            }
        }
        
        reverse(words.begin(), words.end());
        
        string ans;
        for (int k = 0; k < words.size(); ++k) {
            if (k > 0)
                ans += ' ';
            ans += words[k];
        }
        
        return ans;
    }
};
