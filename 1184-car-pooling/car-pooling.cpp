class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> timestamp;
        for (const auto& trip : trips) {
            timestamp[trip[1]] += trip[0];
            timestamp[trip[2]] -= trip[0];
        }
        for (const auto& entry : timestamp) {
            capacity -= entry.second;
            if (capacity < 0)
                return false;
        }
        return true;
    }
};