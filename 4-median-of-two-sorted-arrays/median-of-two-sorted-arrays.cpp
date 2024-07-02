class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr(nums1.size() + nums2.size());
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), arr.begin());
        int n = arr.size();
        double median;
        if (n % 2 == 0) {
            median = (double(arr[n / 2 - 1]) + double(arr[n / 2])) / 2;
        } else {
            median = double(arr[n / 2]);
        }
        return median;
    }
};
