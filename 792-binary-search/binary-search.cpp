class Solution {
public:
    int bs(vector<int> arr, int low, int high, int n){
        while(low<=high){
            int mid = low+(high-low)/2;

            if(arr[mid] == n)
                return mid;
            
            if(arr[mid]<n)
                low = mid+1;
            else
                high = mid -1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return bs(nums,0,nums.size()-1,target);
    }
};