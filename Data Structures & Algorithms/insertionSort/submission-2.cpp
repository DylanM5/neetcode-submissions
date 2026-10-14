// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
   public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> ret{};

        if (!pairs.empty()) ret.push_back(pairs);
        int i{1};
        while (i < pairs.size()) {
            Pair current = pairs[i];
            int j{i};

            while (j > 0 && pairs[j - 1].key > current.key) {
                pairs[j] = pairs[j - 1];
                --j;
            }

            pairs[j] = current;
            ret.push_back(pairs);
            ++i;
        }

        return ret;
    }
};
