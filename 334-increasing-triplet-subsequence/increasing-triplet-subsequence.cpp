class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int l = INT_MAX, r = INT_MAX;
        for (int i : nums) {
            if (i <= l) {
                l = i;
            } else if (i <= r) {
                r = i;
            } else {
                return true;
            }
        }
        return false;
    }
};
