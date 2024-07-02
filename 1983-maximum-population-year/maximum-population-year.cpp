class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int population[2051] = {0};

        for(const auto& log: logs){
            population[log[0]]++;
            population[log[1]]--;
        }
        int maxPopulation= 0;
        int maxYear = 1950;
        int currentPopulation = 0;

        for(int year = 1950; year< 2051; year++){
            currentPopulation+=population[year];
            if(currentPopulation>maxPopulation){
                maxPopulation = currentPopulation;
                maxYear= year;
            }
        }
        return maxYear;
    }
};