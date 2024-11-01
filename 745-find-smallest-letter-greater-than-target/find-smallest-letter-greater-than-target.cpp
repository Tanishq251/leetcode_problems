class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0;
        int high = letters.size() - 1;
        
        // If the target character is greater than or equal to the last character,
        // the answer should wrap around to the first character
        if (target >= letters[high]) {
            return letters[0];
        }
        
        // Binary search for the next greatest letter
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (letters[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        // The 'low' index will be at the smallest character greater than target
        return letters[low];
    }
};
