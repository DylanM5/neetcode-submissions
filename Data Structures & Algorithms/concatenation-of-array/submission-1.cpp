class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int old_sz = nums.size();
        int sz = old_sz * 2;
        // int *ans{new int[sz]};
        vector<int> ans(sz);
        for (int i{0}; i < old_sz; ++i){
            ans[i] = nums[i];
        }
        for (int i{old_sz}; i < sz; ++i){
            ans[i] = nums[i - old_sz];
        }
        return ans;
    }
};