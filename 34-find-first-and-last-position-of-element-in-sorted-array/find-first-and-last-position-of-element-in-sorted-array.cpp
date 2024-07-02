class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int start = -1, end = -1;
        
        // Find the leftmost occurrence of target
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                if (nums[mid] == target)
                    start = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        // If start was not updated, target is not in nums
        if (start == -1)
            return {-1, -1};
        
        // Find the rightmost occurrence of target
        left = start; // Search in the right half from start
        right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                if (nums[mid] == target)
                    end = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return {start, end};
    }
};
