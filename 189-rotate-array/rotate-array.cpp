class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        k = k % n;
        if (k == 0) return;
        
        vector<int> rotated(n);
        
        for (int i = 0; i < n; i++) {
            rotated[(i + k) % n] = arr[i];
        }
        
        for (int i = 0; i < n; i++) {
            arr[i] = rotated[i];
        }
    }
};