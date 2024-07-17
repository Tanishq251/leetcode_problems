class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,0));

        int left =0, top=0, right=n-1, bottom=n-1;

        int digit=1;


        while(left<=right && top<=bottom){
            

            for(int i=left;i<=right;i++){
                matrix[top][i]=digit++;
            }
            top++;

            for(int i=top;i<=bottom;i++){
                matrix[i][right]=digit++;
            }
            right--;

            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    matrix[bottom][i]=digit++;
                }
                bottom --;
            }

            if(left<=right){
                for(int i=bottom; i>=top; i--){
                    matrix[i][left]= digit++;
                }
                left++;
            }
        }
        return matrix;
    }
};