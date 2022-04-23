#include "tic_tac_toe_data.h"

void TicTacToeData::save_games(const std::vector<std::unique_ptr<TicTacToe>>& games)
{
    std::ofstream out_file;
    out_file.open("tic_tac_toe.txt"); // opens file
    for(auto& game: games)
    {
        for(auto& c : game->get_pegs())
        {
            out_file<<c;
        }

        out_file<<game->get_winner()<<"\n";
    }

    out_file.close();
}

std::vector<std::unique_ptr<TicTacToe>> TicTacToeData::get_games()
{
    std::vector<std::unique_ptr<TicTacToe>> boards;
    std::ifstream inpfile;
    inpfile.open("tic_tac_toe.txt");
    std::string line;
    if (inpfile.is_open())
    {
        while (std::getline(inpfile, line))
        {
            std::vector<std::string> pegs;
            for (auto i = 0; i < (line.size() - 1); ++i)
            {
                std::string ch(1, line[i]);
                pegs.push_back(ch);
            }
            std::string winner_char{line[line.size() - 1]};
            std::unique_ptr<TicTacToe> board;

            if      (pegs.size() == 9)
            {
                board = std::make_unique<TicTacToe3>(pegs, winner_char);
            }
            else if (pegs.size() == 16)
            {
                board = std::make_unique<TicTacToe4>(pegs, winner_char);
            }
            boards.push_back(std::move(board));
        }
        inpfile.close();
    }
    return boards;
}