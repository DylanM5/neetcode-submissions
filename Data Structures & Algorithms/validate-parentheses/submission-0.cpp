#include <stack>
#include <string>

class Solution {
   public:
    bool isValid(string s) {
        if (s.empty()) return false;
        std::stack<char> stk;

        for (const char c : s) {
            if (c == '(' || c == '{' || c == '[')
                stk.push(c);
            else if (c == ')' || c == '}' || c == ']'){
                if (stk.empty())
                    return false;
                char top = stk.top();
                bool c1 = top == '(' && c == ')';
                bool c2 = top == '{' && c == '}';
                bool c3 = top == '[' && c == ']';
                bool match = c1 || c2 || c3;
                if (match)
                    stk.pop();
                else
                    return false;
            }
        }
        return stk.empty();
    }
};
