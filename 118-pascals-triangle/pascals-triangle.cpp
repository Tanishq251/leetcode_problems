class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1); // Initialize each row with 1s
            for (int j = 1; j < i; j++) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j]; // Calculate values based on the previous row
            }
            triangle.push_back(row); // Add the current row to the triangle
        }
        
        return triangle;
    }
};