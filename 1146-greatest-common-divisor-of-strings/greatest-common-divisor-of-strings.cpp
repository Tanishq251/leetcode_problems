class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.length() < str2.length()) 
            return gcdOfStrings(str2, str1); // Ensure str1 is always the longer one
        
        if (str1.find(str2) != 0) 
            return ""; // If str1 does not start with str2, there is no common divisor
        
        if (str2 == "") 
            return str1; // If str2 is empty, return str1 as the GCD
        
        // Recur with the substring of str1 from length of str2 to the end
        return gcdOfStrings(str1.substr(str2.length()), str2);
    }
};
