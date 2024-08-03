class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int sum = 0, cur =0, ans =0;
        for(int i=0; i<n; i++){
            sum+=gas[i] - cost[i];
            cur+=gas[i] - cost[i];

            if(cur < 0){
                ans = i+1;
                cur = 0;
            }
        }
        return sum < 0 ? -1: ans;
    }
};