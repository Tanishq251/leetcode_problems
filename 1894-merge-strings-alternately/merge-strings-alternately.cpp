class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string res = "";
        int i = 0, j = 0;
        while (i < word1.length() && j < word2.length())
        {
            res += word1[i];
            res += word2[j];
            i++;
            j++;
        }
        while (i < word1.length())
        {
            res += word1[i];
            i++;
        }
        while (j < word2.length())
        {
            res += word2[j];
            j++;
        }
        return res;
    }
};
