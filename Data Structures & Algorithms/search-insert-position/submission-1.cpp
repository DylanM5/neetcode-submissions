class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int high{(int)nums.size() - 1};
        int low{0};
        int middle{};
        int ret{(int)nums.size()};

        while (low <= high) {
            middle = low + (high - low) / 2;

            if (nums[middle] == target)
                return middle;

            else if (nums[middle] < target)
                low = middle + 1;

            else{
                ret = middle;
                high = middle - 1;
            }
        }
        return ret;
    }
};