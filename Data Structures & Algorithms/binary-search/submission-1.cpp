#include <cmath>

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int high{(int)nums.size() - 1};
        int low{0};
        int middle = std::floor((low + high) / 2);

        while (nums[middle] != target) {
            if (high < low)
                return -1;

            else if (nums[middle] < target)
                low = middle + 1;

            else if (nums[middle] > target)
                high = middle - 1;

            middle = std::floor((low + high) / 2);
        }
        return middle;
    }
};
