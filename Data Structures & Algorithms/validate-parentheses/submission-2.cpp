class Solution {
public:
    bool isValid(string s) {
        std::stack<char> bracket;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') bracket.push(c);
            if (c == ')') {
                if (bracket.empty() || bracket.top() != '(') return false;
                bracket.pop();
            }
            else if (c == ']') {
                if (bracket.empty() || bracket.top() != '[') return false;
                bracket.pop();
            }
            else if (c == '}') {
                if (bracket.empty() || bracket.top() != '{') return false;
                bracket.pop();
            }
        }

        return bracket.empty();
    }
};
