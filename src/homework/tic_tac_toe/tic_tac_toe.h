#include <string>
#include <vector>
#include <iostream>

//h
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

class TicTacToe {
    friend std::ostream& operator<<(std::ostream& out, const TicTacToe&
    game);
    friend std::istream& operator>>(std::istream& in, TicTacToe& game);

public:
    TicTacToe()= default;
    explicit TicTacToe(int size): pegs(size * size, "") {};
    bool game_over();
    void start_game(std::string first_player);
    void mark_board(int position);
    [[nodiscard]] std::string get_player() const {return player;};
    std::string get_winner() {return winner;};

protected:
    std::vector<std::string> pegs;
    virtual bool check_column_win();
    virtual bool check_row_win();
    virtual bool check_diagonal_win();

private:
    std::string player;
 
    std::string winner;
    void set_next_player();
    bool check_board_full();
    void clear_board();

    void set_winner();
};
#endif