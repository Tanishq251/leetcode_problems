class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==1) return {0,1};
        vector<int> arr = grayCode(n-1);
        vector<int> ans = arr;
        for(int i=arr.size()-1;i>=0;i--){
            ans.push_back(arr[i]+ (int)pow(2,n-1));
        }
        return ans;
    }
};