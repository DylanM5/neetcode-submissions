class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {};
        bool cols[9][9] = {};
        bool boxes[9][9] = {};

        for (int r{0}; r < 9; ++r) {
            for (int c{0}; c < 9; ++c) {
                char& current = board[r][c];
                if (current == '.') continue;

                int idx = current - '1';
                int box = (r / 3) * 3 + (c / 3);
                if (rows[r][idx] || cols[c][idx] || boxes[box][idx]) return false;

                rows[r][idx] = cols[c][idx] = boxes[box][idx] = true;
            }
        }

        return true;
    }
};
