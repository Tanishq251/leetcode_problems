class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1, ans=INT_MAX;

        while(l<=r){
            int mid =(l+r)/2;
            
            if(nums[l]<=nums[r]){
                ans=min(ans,nums[l]);
                break;
            }

            if(nums[l]<= nums[mid]){
                ans = min(ans, nums[l]);
                l =mid+1;
            }

            else{
                r = mid -1;
                ans = min(ans, nums[mid]);
            }
        }
        return ans;
    }
};