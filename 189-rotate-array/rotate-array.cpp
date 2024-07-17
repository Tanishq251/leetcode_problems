class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        k = k % n;  // Handle cases where k is greater than the size of the array
        if (k == 0) return;  // No need to rotate if k is 0
        
        // Reverse the entire array
        reverse(arr.begin(), arr.end());
        // Reverse the first k elements
        reverse(arr.begin(), arr.begin() + k);
        // Reverse the remaining n - k elements
        reverse(arr.begin() + k, arr.end());
    }
};