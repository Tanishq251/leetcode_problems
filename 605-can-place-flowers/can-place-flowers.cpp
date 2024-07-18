class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int t = flowerbed.size();
        for (int i = 0; i < t && n > 0; i++) {
            if (flowerbed[i] == 0) {
                bool emptyLeft = (i == 0 || flowerbed[i - 1] == 0);
                bool emptyRight = (i == t - 1 || flowerbed[i + 1] == 0);
                if (emptyLeft && emptyRight) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }
        return n == 0;
    }
};
