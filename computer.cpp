#include "XO_Classes.hpp"


int Computer::minimax(Board &b, int depth, bool ai) {
    int score = 0, bestval = 0;
    if (b.is_winner()) {
        if (ai) return -1;
        else return 1;
    } else {
        if (depth < 9) {
            if (ai) {
                bestval = -999;
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        if (b.board[i][j] == 0) {
                            b.board[i][j] = 'X';
                            score = minimax(b, depth + 1, false);
                            b.board[i][j] = 0;
                            bestval = max(bestval, score);

                        }
                    }
                }
                return bestval;
            } else {
                bestval = 999;
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        if (b.board[i][j] == 0) {
                            b.board[i][j] = 'O';
                            score = minimax(b, depth + 1, true);
                            b.board[i][j] = 0;
                            bestval = min(bestval, score);
                        }
                    }
                }
                return bestval;
            }
        } else
            return 0;

    }
}

Computer::Computer() = default;

int Computer::bestMove(Board& b) {
    int x = -1, y = -1;
    int score = 0, bestScore = -999;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (b.board[i][j] == 0) {
                b.board[i][j] = 'X';
                score = minimax(b, b.n_moves+1, false);
                b.board[i][j] = 0;
                if (score > bestScore) {
                    bestScore = score;
                    x = i;
                    y = j;
                }
            }
        }
    }
    return x * 3 + y;
}

