class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        // int n = nums.size();
        // if(n==0){
        //     return 0;
        // }

        // int i = 0;
        // for(int j =1; j<n; j++){
        //     if(nums[j] != nums[i]) {
        //         i++;
        //         nums[i] = nums[j];
        //     }
        // }
        // return i+1;
        if (nums.empty()) return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) nums[++i] = nums[j];
        }
        return i + 1;
    }
};