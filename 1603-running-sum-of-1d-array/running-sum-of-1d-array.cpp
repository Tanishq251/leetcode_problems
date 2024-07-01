class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            ans[i] = nums[i] + (i==0?0:ans[i-1]);
        }
        return ans;
    }
};