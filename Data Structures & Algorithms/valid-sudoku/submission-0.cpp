class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col) {
        
        //check for horizontal and vertical similarities
        for (int i = 0; i < 9; ++i) {
            if (i == col) continue;
            else if (board[row][i] == board[row][col]) return false;
        }

        for (int i = 0; i < 9; ++i) {
            if (i == row) continue;
            else if (board[i][col] == board[row][col]) return false;
        }
        

        //check for box constraints
        int start_i = row/3 * 3; //corner points of each box
        int start_j = col/3 * 3;

        for (int i = start_i; i < start_i +3; ++i) {
            for (int j = start_j; j < start_j +3; ++j) {
                if (i==row && j == col)continue;
                else if (board[i][j] == board[row][col]) return false;
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {

                if (board[i][j] != '.') {
                    if (isValid(board, i, j)) continue;
                    else return false;
                }
            }
        }

        return true;
    }
};
