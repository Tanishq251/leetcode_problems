class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> arr(n,vector<int>(n,0));

        int l=0, r=n-1, top=0, last =n-1;
        int matr=1;

        while(l<=r && top<=last){
            for(int i=l;i<=r;i++){
                arr[top][i]=matr++;
            }
            top++;

            for(int i=top; i<= last; i++){
                arr[i][r]=matr++;
            }
            r--;

            if(top<=last){
                for(int i=r;i>=l;i--){
                    arr[last][i] = matr++;
                }
                last--;
            }

            if(l<=r){
                for(int i=last; i>=top; i--){
                    arr[i][l]=matr++;
                }
                l++;
            }

        }
        return arr;
    }
};