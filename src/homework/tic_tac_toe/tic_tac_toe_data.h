#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include <fstream>
#include <memory>

//Header Guards
#ifndef TIC_TAC_TOE_DATA_H
#define TIC_TAC_TOE_DATA_H

class TicTacToeData
{
public:
    static void save_games(const std::vector<std::unique_ptr<TicTacToe>>& games);
    static std::vector<std::unique_ptr<TicTacToe>> get_games();
private:
    static const std::string FILE_NAME = "tic_tac_toe.dat";
};

#endif