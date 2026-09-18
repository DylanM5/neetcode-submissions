class Solution {
   public:
    int calPoints(vector<string>& operations) {
        int score{0};
        vector<int> stack{};

        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "+") {
                stack.push_back(stack[stack.size() - 1] + stack[stack.size() - 2]);
            } else if (operations[i] == "C") {
                stack.pop_back();
            } else if (operations[i] == "D") {
                stack.push_back(stack.back() * 2);
            } else {
                stack.push_back(stoi(operations[i]));
            }
        }
        for (int i{0}; i < stack.size(); i++) {
            score += stack[i];
        }

        return score;
    }
};
