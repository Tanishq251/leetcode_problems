#include <vector>

class Solution {
public:
    std::vector<int> rearrangeArray(std::vector<int>& a) {
        std::vector<int> result(a.size(), 0);
        
        // Separate positive and negative numbers
        std::vector<int> b, c;
        for (int num : a) {
            (num < 0) ? c.push_back(num) : b.push_back(num);
        }
        
        int count = 0, counts = 0;
        for (int i = 0; i < a.size(); i++) {
            if (i % 2) {
                result[i] = c[count++];
            } else {
                result[i] = b[counts++];
            }
        }
        
        return result;
    }
};
