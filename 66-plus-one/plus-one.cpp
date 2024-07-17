class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Iterate from the rightmost digit
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                // Increment the current digit by 1 and return the modified vector
                digits[i]++;
                return digits;
            } else {
                // Set the current digit to 0 and continue to the next digit
                digits[i] = 0;
            }
        }
        
        // If all digits are 9, add a new digit 1 at the beginning of the vector
        digits.insert(digits.begin(), 1);
        return digits;
    }
};