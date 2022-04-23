//h
#include <utility>

#include "tic_tac_toe.h"

#ifndef TIC_TAC_TOE_3_H
#define TIC_TAC_TOE_3_H

class TicTacToe3 : public TicTacToe
{
public:
    TicTacToe3() : TicTacToe(3){} // Default constructor + initializer
    TicTacToe3(std::vector<std::string> p, const std::string& winner) : TicTacToe(std::move(p), get_winner()){}

private:
    bool check_row_win() override;
    bool check_column_win() override;
    bool check_diagonal_win() override;

};

#endif