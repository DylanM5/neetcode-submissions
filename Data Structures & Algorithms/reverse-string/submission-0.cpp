class Solution {
public:
    void reverseString(vector<char>& s) {
        int i{0};
        int j{static_cast<int>(s.size()) - 1};
        char temp{};
        while (i < j){
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            ++i;
            --j;
        }
    }
};