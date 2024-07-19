class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> numCount;
        int operations = 0;
        
        for (int num : nums) {
            int complement = k - num;
            if (numCount[complement] > 0) {
                
                // If the complement exists in the map, we have found a pair
                operations++;
                numCount[complement]--; // Decrease the count of the complement
            } else {
                // Otherwise, store the count of the current number
                numCount[num]++;
            }
        }
        
        return operations;
    }
};
