class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(const auto& i: tokens){
            if(i == "+" || i == "-" || i == "*" || i == "/"){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();

                if(i == "+") st.push(b+a);
                else if(i == "-") st.push(b-a);
                else if(i == "*") st.push(b*a);
                else st.push(b/a);
            }
            else{
                st.push(stoi(i));
            }
        }
        return st.top();
    }
};