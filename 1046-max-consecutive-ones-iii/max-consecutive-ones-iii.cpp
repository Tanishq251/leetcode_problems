class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxCount = 0, j=0, zeroCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                zeroCount++;
            }
            while(zeroCount > k)
            {
                if (nums[j] == 0)
                {
                    zeroCount--;
                }
                j++;
            }
            maxCount = max(maxCount, i-j+1);
        }
        return maxCount;
    }
};