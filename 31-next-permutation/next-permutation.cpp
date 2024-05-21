class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int t = nums.size();

        int n = -1;
        for(int i = t-2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                n = i;
                break;
            }
        }
        if(n == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i = t-1; i > n; i--) {
            if(nums[i] > nums[n]) {
                swap(nums[i], nums[n]);
                break;
            }
        }

        reverse(nums.begin() + n + 1, nums.end());
    }
};