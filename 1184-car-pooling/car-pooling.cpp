class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> arr(1001, 0);
        for (auto x : trips)
        {
            arr[x[1]] += x[0];
            arr[x[2]] -= x[0];
        }
        for (int i = 0; i < arr.size(); i++)
        {
            capacity -= arr[i];
            if (capacity < 0)
                return false;
        }
        return true;
    }
};