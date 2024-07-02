class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1, maxLeft = 0,
            maxRight = 0, water = 0;
        while (left < right)
        {
            if (height[left] <= height[right])
            {
                if (height[left] >= maxLeft)
                    maxLeft = height[left];
                else
                    water += maxLeft - height[left];
                left++;
            }
            else
            {
                if (height[right] >= maxRight)
                    maxRight = height[right];
                else
                    water += maxRight - height[right];
                right--;
            }
        }
        return water;
    }
};