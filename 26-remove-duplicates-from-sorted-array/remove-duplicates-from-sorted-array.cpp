class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        
        int j = 0; // Pointer for the unique elements
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[j]) {
                j++;
                nums[j] = nums[i];
            }
        }
        
        return j + 1; // Length of the array with unique elements
    }
};