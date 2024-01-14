class Solution {
public:
    vector<int> rearrangeArray(vector<int>& a) {
        std::vector<int> b;
    std::vector<int> c;
    
    // Separate positive and negative numbers into vectors b and c
    for(int i = 0; i < a.size(); i++) {
        if (a[i] < 0) {
            c.push_back(a[i]);
        } else {
            b.push_back(a[i]);
        }
    }
    
    std::vector<int> d;
    int count = 0; // Initialize count to 0
    int counts = 0; // Initialize counts to 0
    
    // Fill vector d with alternate elements from vectors b and c
    for(int i = 0; i < a.size(); i++) {
        if (i % 2) {
            if (count < c.size()) {
                d.push_back(c[count]);
                count++;
            }
        } else {
            if (counts < b.size()) {
                d.push_back(b[counts]);
                counts++;
            }
        }
    }
    
    return d;
    }
};