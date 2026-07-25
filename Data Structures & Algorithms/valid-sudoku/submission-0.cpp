class Solution {
   public:
    bool checksq(int i, int j, vector<vector<char>>& board) {
        unordered_set<char> st;

        for (int k = i; k < i + 3; k++) {
            for (int t = j; t < j + 3; t++) {
                if (board[k][t] == '.') continue;
                if (st.contains(board[k][t])) return false;
                st.insert(board[k][t]);
            }
        }
        return true;
    }

    bool checkrow(int i, vector<vector<char>>& board) {
        unordered_set<char> st;
        for (int k = 0; k < 9; k++) {
            if (board[i][k] == '.') continue;
            if(st.contains(board[i][k])) return false;
            st.insert(board[i][k]);
        }
        return true;
    }

    bool checkcol(int i, vector<vector<char>>& board) {
        unordered_set<char> st;
        for (int k = 0; k < 9; k++) {
            if (board[k][i] == '.') continue;
            if(st.contains(board[k][i])) return false;
            st.insert(board[k][i]);
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!(checksq(i, j, board))) return false;
            }
        }

        for (int i = 0; i < 9; i++) {
            if (!checkrow(i, board)) return false;
        }

        for (int i = 0; i < 9; i++) {
            if (!checkcol(i, board)) return false;
        }

        return true;
    }
};