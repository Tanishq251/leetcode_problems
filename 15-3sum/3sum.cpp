class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());\

        int n = nums.size();
        for(int i=0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;

            int left = i+1;
            int right = n-1;

            while(left < right){
                
                int sums = nums[i] + nums[left] + nums[right];
                if(sums == 0){
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left ++;
                    right --;

                    while( left < right && nums[left] == nums[left-1]) left++;
                    while(left < right && nums[right] == nums[right+1]) right--;
                }
                else if(sums > 0) right--;
                else left++;
            }
        }
        return ans;
            
    }
};