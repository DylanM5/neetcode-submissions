class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret{};
        for (size_t i{0}; i < nums.size(); ++i)
            ret ^= nums[i];
        return ret;
    }
};
