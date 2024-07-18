class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str_nums(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            str_nums[i] = to_string(nums[i]);
        }

        sort(str_nums.begin(), str_nums.end(), [](const string &a, const string &b) {
            return a + b > b + a;
        });

        string res;
        for (const string &num : str_nums) {
            res += num;
        }

        if (res[0] == '0') {
            return "0";
        }

        return res;
    }
};
