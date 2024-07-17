class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        for(int i=0;i<n;i++){
            if(nums[i] != 0){
                nums[l++] =nums[i]; 
            }
        }
        while(l<n){
            nums[l++]=0;
        }
    }
};