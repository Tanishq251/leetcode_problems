class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for (int i = 0; i < 13; i++) {
            while (s.find(roman[i]) == 0) {
                result += values[i];
                s.erase(0, roman[i].size());
            }
        }
        return result;
    }
};