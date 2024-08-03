#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();  
        
        int count = 1;
        int index = 1;

        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]){
                if(count < 2){
                    nums[index++] = nums[i];
                    count++;
                }
            }
            else{
                nums[index++]= nums[i];
                count =1;
            }
        }
        return index;
        
    }
};
