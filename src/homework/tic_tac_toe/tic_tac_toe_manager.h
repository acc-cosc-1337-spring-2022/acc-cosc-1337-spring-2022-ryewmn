//h
#include "tic_tac_toe.h"
#include <vector>
#include <string>
#include <memory>


using std::unique_ptr;
using std::make_unique;
#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

class TicTacToeManager : public TicTacToe {

    friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager);

public:
    void save_game(unique_ptr<TicTacToe> &b);
    void get_winner_total(int& o, int& w, int& t) const;

private:
    std::vector<unique_ptr<TicTacToe>> games;
    int x_win{0};
    int o_win{0};
    int ties{0};
    void update_winner_count(const std::string& winner);


};

#endif
