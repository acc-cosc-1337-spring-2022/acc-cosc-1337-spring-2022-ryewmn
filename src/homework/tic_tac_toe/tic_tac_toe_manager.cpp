//cpp

#include "tic_tac_toe_manager.h"
using std::cout;


std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager){  // friends method
    out << "*- All Games Played -*\n";
    for (const auto& game: manager.games) {
        out << game << "\n";
    }
    return out;
}

void TicTacToeManager::save_game(TicTacToe b){ // Public
    games.push_back(b);
    update_winner_count(b.get_winner());

}

void TicTacToeManager::get_winner_total(int& o, int& w, int& t) const{ // Score manager
    w = x_win;
    o = o_win;
    t = ties;
    cout << "O wins: " << o << "\n";
    cout << "X wins: " << w << "\n";
    cout << "Ties: " << t << "\n";
}

void TicTacToeManager::update_winner_count(const std::string& winner){ // Private method
    if (winner == "X") {
        x_win++;
    } else if (winner == "O") {
        o_win++;
    } else {
        ties++;
    }
}