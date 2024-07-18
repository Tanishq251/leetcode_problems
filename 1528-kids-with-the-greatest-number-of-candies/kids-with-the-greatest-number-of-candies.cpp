class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> arr(n);  
        
        int maxCandies = *max_element(candies.begin(), candies.end()); 
        
        for (int i = 0; i < n; i++) {
            int s = candies[i] + extraCandies;
            arr[i] = (s >= maxCandies); 
        }
        
        return arr;
    }
};
