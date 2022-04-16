#include "tic_tac_toe.h"
#include <iostream>
#include <utility>

using std::string, std::cout;

// Friend methods
std::ostream& operator<<(std::ostream& out, const TicTacToe& game){
    if (game.pegs.size() == 9) {
        for(int i = 0; i < 9; i+=3) {
            out << game.pegs[i] << "|" << game.pegs[i +1] << "|" << game.pegs[i+2] << "\n";
        }
    } else {
        for(int i = 0; i < 16; i+=4) {
            out << game.pegs[i] << "|" << game.pegs[i +1] << "|" << game.pegs[i+2] << "|" << game.pegs[i+3] << "\n";
        }
    }
    return out;
}


std::istream &operator>>(std::istream &in, TicTacToe &game) {
    int position;

    if (game.pegs.size() == 9) {
        cout << "Enter position [1-9]: ";
        in >> position;
    } else {
        cout << "Enter position [1-16]: ";
        in >> position;
    }

    if (position >= 1 && position <= 9) {
        game.mark_board(position);


    } else if (!in) {
        cout << "\nInvalid Position" << "\n";
        in.clear();
        in.ignore();
    }

    return in;
}


// Public methods
    void TicTacToe::start_game(string first_player) {
        player = std::move(first_player);
        clear_board();
    }

    void TicTacToe::mark_board(int position) {
        pegs[position - 1] = player;
        set_next_player();
    }

    bool TicTacToe::game_over() {
        /* update class function to determine a win by checking for row win or
          column win or diagonal win.
          */
        bool over;
        if (check_diagonal_win() || check_row_win() || check_column_win()) {
            set_winner();
            over = true;
        } else if (check_board_full()) {
            over = true;
            winner = "C";
        } else {
            over = false;
        }
        return over;
    }


    void TicTacToe::set_next_player() {
        if (player == "X") {
            player = "O";
        } else {
            player = "X";
        }
    }

    bool TicTacToe::check_board_full() {
        for (const auto &peg: pegs) {
            if (peg == " ") {
                return false;
            }
        }
        return true;
    }
    void TicTacToe::clear_board() {
        if (pegs.size() == 9) {
            for (int i = 0; i < 9; i++) {
                pegs[i] = " ";
            }
        } else {
            for (int i = 0; i < 16; i++) {
                pegs[i] = " ";
            }
        }
    }

    bool TicTacToe::check_column_win() {
        return false;
    }

    bool TicTacToe::check_row_win() {

        return false;
    }
    bool TicTacToe::check_diagonal_win() {

        return false;
    }

    void TicTacToe::set_winner() {
        /* If player is X set winner to O otherwise set winner to X
        */
        if (player == "X") {
            winner = "O";
        } else {
            winner = "X";
        }
    }


