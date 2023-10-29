class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int i = 0, j = 0;
        
        while (j < nums.size()) {
         
            if (j == 0 || nums[j] != nums[j - 1]) {
            
                nums[i] = nums[j];
            
                i++;
            }
           
            j++;
        }
       
        return i;
    }
};
