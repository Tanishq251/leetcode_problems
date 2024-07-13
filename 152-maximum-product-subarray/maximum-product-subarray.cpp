class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        double max_val = INT_MIN;
        double left = 1, right = 1;
        for (int i = 0; i < n; ++i) {
            left *= nums[i];
            right *= nums[n-1-i];
            max_val = max({max_val, left, right});
            if (left == 0) left = 1;
            if (right == 0) right = 1;
        }
        return max_val;
    }
};