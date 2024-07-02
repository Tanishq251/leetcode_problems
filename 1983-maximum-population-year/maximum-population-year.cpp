class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int arr[2051];
        for(int i = 0; i< logs.size(); i++){
            for(int j = logs[i][0]; j < logs[i][1]; j++){
                arr[j]++;
            }
        }
        int max=0, year=0;
        for(int i = 0; i <2051;i++){
            if(arr[i]>max){
                max = arr[i];
                year= i;
            }
        }
        return year;

    }
};