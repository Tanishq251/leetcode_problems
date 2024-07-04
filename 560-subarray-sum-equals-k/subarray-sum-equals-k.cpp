class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int N=nums.size();
        unordered_map<int, int> prefixSumCount;
        int currentSum = 0;
        int subArrayCount = 0;
    
        prefixSumCount[0] = 1;
    
        for (int i = 0; i < N; i++) {
            currentSum += nums[i];
    
            if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
                subArrayCount += prefixSumCount[currentSum - k];
            }
    
            prefixSumCount[currentSum]++;
        }
        return subArrayCount;
    }
};