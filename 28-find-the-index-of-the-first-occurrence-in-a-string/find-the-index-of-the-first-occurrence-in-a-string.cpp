class Solution {
public:
    int strStr(string s, string n) {
        int i = s.length();
        int j = n.length();

        if (j == 0) return 0;

        for (int k = 0; k <= i - j; k++) {
            int x = 0;

            while (x < j) {
                if (s[k + x] != n[x]) {
                    break;
                }
                x++;
            }

            if (x == j) return k;
        }
        return -1;
    }
};