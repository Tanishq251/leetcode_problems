class Solution {
public:
    int candy(vector<int>& arr) {
        int n = arr.size();
        vector<int> a(n,1);

        for(int i=1; i<n ; i++){
            if(arr[i] > arr[i-1]){
                a[i] = a[i-1]+1;
            }
        }

        for(int i=n-2; i>=0; i--){
            if(arr[i] > arr[i+1]){
                a[i] = max( a[i],a[i+1]+1 );
            }
        }

        int total = 0;

        for(int x: a){
            total += x;
        }

        return total;
    }
};