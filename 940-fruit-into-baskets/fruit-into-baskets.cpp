class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();
        int maxCount = 0, j = 0, basketCount = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++)
        {
            map[fruits[i]]++;
            if (map.size() <= 2)
            {
                maxCount = max(maxCount, i - j + 1);
            }
            else
            {
                while (map.size() > 2)
                {
                    map[fruits[j]]--;
                    if (map[fruits[j]] == 0)
                    {
                        map.erase(fruits[j]);
                    }
                    j++;
                }
                maxCount = max(maxCount, i - j + 1);
            }
        }
        return maxCount;
    }
};