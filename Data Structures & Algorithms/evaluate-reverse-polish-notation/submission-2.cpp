class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for (string token : tokens) {
            if (isdigit(token[0]) || isdigit(token[1])) {
                st.push(stoi(token));
                continue;
            }

            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();
            int res = 0;

            if (token == "+") res = operand1 + operand2;
            else if (token == "-") res = operand1 - operand2;
            else if (token == "*") res = operand1 * operand2;
            else if (token == "/") res = operand1 / operand2;

            st.push(res);
        }
        return st.top();
    }
};
