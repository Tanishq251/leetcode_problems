class Solution {
public:
    bool isSubsequence(string s, string t) {
        int slen = s.length();
        int tlen = t.length();

        int indexS = 0;
        int indexT = 0;

        while(indexT < tlen && indexS < slen){
            if(s[indexS] == t[indexT]) indexS++;

            indexT++;
        }

        return indexS == slen;
    }
};