class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         int max_sum = INT_MIN;  // Initialize with negative infinity
        int current_sum = 0;

        for (int num : nums) {
            current_sum = max(num, current_sum + num);
            max_sum = max(max_sum, current_sum);
        }

        return max_sum;
    }
};