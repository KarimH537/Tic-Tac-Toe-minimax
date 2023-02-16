// Class definition for XO_GameManager class


#include <iostream>
#include"XO_Classes.hpp"

using namespace std;

void GameManager::run() {
    Board x_o;
    int x, y;
    Player players[2] = {Computer('x'), Player(2, 'o')};
    x_o.display_board();
    while (true) {

        players[1].get_move(x, y);
        x_o.update_board(x, y, players[1].get_symbol());
        x_o.display_board();
        if (x_o.is_winner()) {
            cout << players[1].to_string() << " wins\n";
            return;
        }
        if (x_o.is_draw()) {
            cout << "Draw!\n";
            return;
        }
        cout << "Computer's turn\n";
        Computer c;
        int n=  c.bestMove(x_o);
        x = n/3;
        y = n%3;
        x_o.update_board(x, y, players[0].get_symbol());
        x_o.display_board();
        if (x_o.is_winner()) {
            cout << "Computer" << " wins\n";
            return;
        }
        if (x_o.is_draw()) {
            cout << "Draw!\n";
            return;
        }
    }
}
