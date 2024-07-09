class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &tp)
    {
        int n = tp.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && tp[st.top()] < tp[i])
            {
                int index = st.top();
                st.pop();
                ans[index] = i - index;
            }
            st.push(i);
        }
        return ans;
    }
};
