class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int minDis=INT_MAX;
        int ans;
        for(int i=0;i<n;i++){
            // use the two pointer approach
            int l = i+1;
            int r = n-1;
            while(l<r){
                int sum = nums[i]+nums[l]+nums[r];
                int dis=abs(sum-target);
                if(dis<minDis){
                    minDis= dis;
                    ans = sum;
                }
                else if(sum>target){
                    r--;
                }
                else if(sum<target){
                    l++;
                }
                else{
                    break;
                }
            }
            if(minDis==0){
                break;
            }
        }
        return ans;
    }
};