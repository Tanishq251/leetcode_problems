class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int ans = 0,maxs = 0,cur = 0;
        for (int i = 0; i < n - 1; i++)
        {
            maxs = max(maxs, i + nums[i]);
            if (i == cur)
            {
                cur = maxs;
                ans++;
            }
        }
        return ans;
    }
};