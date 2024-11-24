class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int i = 0;
        
        // Add characters alternately while both strings have characters
        while (i < word1.size() && i < word2.size()) {
            result += word1[i];
            result += word2[i];
            i++;
        }
        
        // Add remaining characters from word1 if any
        while (i < word1.size()) {
            result += word1[i];
            i++;
        }
        
        // Add remaining characters from word2 if any
        while (i < word2.size()) {
            result += word2[i];
            i++;
        }
        
        return result;
    }
};