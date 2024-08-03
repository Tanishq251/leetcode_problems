class Solution {
public:
    int hIndex(vector<int>& arr) {
        sort(arr.begin(), arr.end(), greater<int>());;

        for(int i=0; i<arr.size(); i++){
            if(arr[i]<i+1){
                return i;
            }
        }
        return arr.size();
    }
};