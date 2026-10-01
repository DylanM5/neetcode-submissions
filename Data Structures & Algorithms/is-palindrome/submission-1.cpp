class Solution {
   public:
    string strip(string& s) {
        int i = 0;
        for (int j = 0; j < s.size(); j++) {
            if (isalnum(s[j])) {
                s[i] = tolower(s[j]);
                i++;
            }
        }
        s.erase(i);
        return s;
    }
    bool isPalindrome(string s) {
        strip(s);
        if (s.empty())
            return true;
        int i{0};
        auto j{s.size() - 1};
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
