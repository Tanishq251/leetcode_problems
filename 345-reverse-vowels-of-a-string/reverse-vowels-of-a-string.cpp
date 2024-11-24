class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        auto isVowel = [](char c) { 
            c = tolower(c); 
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; 
        };
        while (i < j) {
            if (!isVowel(s[i])) i++;
            else if (!isVowel(s[j])) j--;
            else {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};
