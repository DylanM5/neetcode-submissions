class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        double x = std::log2(n);
        return x == std::floor(x);
    }
};