class Solution {
public:
    bool isAnagram(string &s, string &t) {
        bool repeat{false};
        int length = s.length();
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        return s == t;
    }
};
