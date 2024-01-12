class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int> numIndices;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (numIndices.find(complement) != numIndices.end()) {
                return {numIndices[complement], i};
            }
            numIndices[nums[i]] = i;
        }
        return {};
    }
};