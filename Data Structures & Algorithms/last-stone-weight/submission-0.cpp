#include <queue>

class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> heap;
        for (int stone : stones) heap.push(stone);
        while (heap.size() > 1) {
            int x = heap.top();
            heap.pop();
            int y = heap.top();
            heap.pop();

            if (y < x) heap.push(x - y);
        }
        heap.push(0);
        return heap.top();
    }
};
