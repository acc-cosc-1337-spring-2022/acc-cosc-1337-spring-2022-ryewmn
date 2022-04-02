//h
#include "tic_tac_toe.h"
#include <vector>
#include <string>
#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

class TicTacToeManager : public TicTacToe {

    friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager);

public:
    void save_game(TicTacToe b);
    void get_winner_total(int& o, int& w, int& t) const;

private:
    std::vector<TicTacToe> games;
    int x_win{0};
    int o_win{0};
    int ties{0};
    void update_winner_count(const std::string& winner);


};

#endif
