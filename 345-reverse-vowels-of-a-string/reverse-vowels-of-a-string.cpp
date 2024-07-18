class Solution {
public:
    string reverseVowels(string s) {
        int n = s.length();
        int i = 0, j = n - 1;

        auto isVowel = [](char c) {
            c = tolower(c); 
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        while (i <= j) {
            if (isVowel(s[i]) && isVowel(s[j])) {
                swap(s[i], s[j]);
                i++;
                j--;
            } else {
                if (!isVowel(s[i])) {
                    i++;
                }
                if (!isVowel(s[j])) {
                    j--;
                }
            }
        }

        return s;
    }
};
