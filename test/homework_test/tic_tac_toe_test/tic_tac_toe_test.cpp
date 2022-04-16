#define CATCH_CONFIG_MAIN  // These tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

TEST_CASE("Verify Test Configuration", "verification") {
REQUIRE(true == true);
}

TEST_CASE("Test tic tac toe game over for a tie") {
unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
game->start_game("X");
game->mark_board(1);
REQUIRE(game->game_over() == false);
game->mark_board(3);
REQUIRE(game->game_over() == false);
game->mark_board(2);
REQUIRE(game->game_over() == false);
game->mark_board(4);
REQUIRE(game->game_over() == false);
game->mark_board(6);
REQUIRE(game->game_over() == false);
game->mark_board(5);
REQUIRE(game->game_over() == false);
game->mark_board(7);
REQUIRE(game->game_over() == false);
game->mark_board(8);
REQUIRE(game->game_over() == false);
game->mark_board(9);
REQUIRE(game->game_over() == true);
REQUIRE(game->get_winner() == "C");
}


TEST_CASE("Test first player set to X") {
unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
game->start_game("X");
REQUIRE(game->get_player() == "X");
}

TEST_CASE("Test first player set to O") {
unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
game->start_game("O");
REQUIRE(game->get_player() == "O");
}

TEST_CASE("Test win by first column") {
unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
game->start_game("X");
game->mark_board(7);
REQUIRE(game->game_over() == false);
game->mark_board(2);
REQUIRE(game->game_over() == false);
game->mark_board(4);
REQUIRE(game->game_over() == false);
game->mark_board(3);
REQUIRE(game->game_over() == false);
game->mark_board(1);
REQUIRE(game->game_over() == true);
REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by second column") {
unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
game->start_game("X");
game->mark_board(2);
REQUIRE(game->game_over() == false);
game->mark_board(1);
REQUIRE(game->game_over() == false);
game->mark_board(8);
REQUIRE(game->game_over() == false);
game->mark_board(3);
REQUIRE(game->game_over() == false);
game->mark_board(5);
REQUIRE(game->game_over() == true);
REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by third column") {
unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
game->start_game("X");
game->mark_board(3);
REQUIRE(game->game_over() == false);
game->mark_board(2);
REQUIRE(game->game_over() == false);
game->mark_board(6);
REQUIRE(game->game_over() == false);
game->mark_board(4);
REQUIRE(game->game_over() == false);
game->mark_board(9);
REQUIRE(game->game_over() == true);
REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by first row") {
unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
game->start_game("X");
game->mark_board(1);
REQUIRE(game->game_over() == false);
game->mark_board(5);
REQUIRE(game->game_over() == false);
game->mark_board(2);
REQUIRE(game->game_over() == false);
game->mark_board(7);
REQUIRE(game->game_over() == false);
game->mark_board(3);
REQUIRE(game->game_over() == true);
REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by second row") {
unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
game->start_game("X");
game->mark_board(4);
REQUIRE(game->game_over() == false);
game->mark_board(2);
REQUIRE(game->game_over() == false);
game->mark_board(5);
REQUIRE(game->game_over() == false);
game->mark_board(3);
REQUIRE(game->game_over() == false);
game->mark_board(6);
REQUIRE(game->game_over() == true);
REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by third row") {
unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
game->start_game("X");
game->mark_board(7);
REQUIRE(game->game_over() == false);
game->mark_board(2);
REQUIRE(game->game_over() == false);
game->mark_board(8);
REQUIRE(game->game_over() == false);
game->mark_board(3);
REQUIRE(game->game_over() == false);
game->mark_board(9);
REQUIRE(game->game_over() == true);
REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win diagonally from top left") {
unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
game->start_game("X");
game->mark_board(1);
REQUIRE(game->game_over() == false);
game->mark_board(2);
REQUIRE(game->game_over() == false);
game->mark_board(5);
REQUIRE(game->game_over() == false);
game->mark_board(3);
REQUIRE(game->game_over() == false);
game->mark_board(9);
REQUIRE(game->game_over() == true);
REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win diagonally from bottom left") {
unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
game->start_game("X");
game->mark_board(7);
REQUIRE(game->game_over() == false);
game->mark_board(2);
REQUIRE(game->game_over() == false);
game->mark_board(5);
REQUIRE(game->game_over() == false);
game->mark_board(1);
REQUIRE(game->game_over() == false);
game->mark_board(3);
REQUIRE(game->game_over() == true);
REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test TicTacToe manager get winner total function") {
int o, w, t; // X, O, and tie totals

TicTacToeManager manager;
unique_ptr<TicTacToe> game1 = make_unique<TicTacToe3>();
game1->start_game("O");
game1->mark_board(4);
REQUIRE(game1->game_over() == false);
game1->mark_board(1);
REQUIRE(game1->game_over() == false);
game1->mark_board(5);
REQUIRE(game1->game_over() == false);
game1->mark_board(2);
REQUIRE(game1->game_over() == false);
game1->mark_board(6);
REQUIRE(game1->game_over() == true);
REQUIRE(game1->get_winner() == "O");
manager.save_game(game1);
// End game1
unique_ptr<TicTacToe> game2 = make_unique<TicTacToe3>();
game2->start_game("X");
game2->mark_board(4);
REQUIRE(game2->game_over() == false);
game2->mark_board(1);
REQUIRE(game2->game_over() == false);
game2->mark_board(5);
REQUIRE(game2->game_over() == false);
game2->mark_board(2);
REQUIRE(game2->game_over() == false);
game2->mark_board(6);
REQUIRE(game2->game_over() == true);
REQUIRE(game2->get_winner() == "X");
manager.save_game(game2);
// End game2
unique_ptr<TicTacToe> game3 = make_unique<TicTacToe3>();
game3->start_game("O");
game3->mark_board(1);
REQUIRE(game3->game_over() == false);
game3->mark_board(2);
REQUIRE(game3->game_over() == false);
game3->mark_board(3);
REQUIRE(game3->game_over() == false);
game3->mark_board(5);
REQUIRE(game3->game_over() == false);
game3->mark_board(4);
REQUIRE(game3->game_over() == false);
game3->mark_board(7);
REQUIRE(game3->game_over() == false);
game3->mark_board(6);
REQUIRE(game3->game_over() == false);
game3->mark_board(9);
REQUIRE(game3->game_over() == false);
game3->mark_board(8);
REQUIRE(game3->game_over() == true);
REQUIRE(game3->get_winner() == "C");
manager.save_game(game3);
// End game 3

manager.get_winner_total(o,w,t);
REQUIRE(o == 1);
REQUIRE(w == 1);
REQUIRE(t == 1);
}

// TicTacToe4 Tests
TEST_CASE("Test tic tac toe game over for a tie 4") {
unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
game->start_game("X");
game->mark_board(1);
REQUIRE(game->game_over() == false);
game->mark_board(3);
REQUIRE(game->game_over() == false);
game->mark_board(2);
REQUIRE(game->game_over() == false);
game->mark_board(4);
REQUIRE(game->game_over() == false);
game->mark_board(6);
REQUIRE(game->game_over() == false);
game->mark_board(5);
REQUIRE(game->game_over() == false);
game->mark_board(7);
REQUIRE(game->game_over() == false);
game->mark_board(8);
REQUIRE(game->game_over() == false);
game->mark_board(9);
REQUIRE(game->game_over() == false);
game->mark_board(10);
REQUIRE(game->game_over() == false);
game->mark_board(11);
REQUIRE(game->game_over() == false);
game->mark_board(16);
REQUIRE(game->game_over() == false);
game->mark_board(12);
REQUIRE(game->game_over() == false);
game->mark_board(13);
REQUIRE(game->game_over() == false);
game->mark_board(14);
REQUIRE(game->game_over() == false);
game->mark_board(15);
REQUIRE(game->game_over() == true);
REQUIRE(game->get_winner() == "C");
}

TEST_CASE("Test first player set to X 4") {
unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
game->start_game("X");
REQUIRE(game->get_player() == "X");
}

TEST_CASE("Test first player set to O 4") {
unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
game->start_game("O");
REQUIRE(game->get_player() == "O");
}

TEST_CASE("Test win by first column 4") {
unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
game->start_game("X");
game->mark_board(1);
REQUIRE(game->game_over() == false);
game->mark_board(2);
REQUIRE(game->game_over() == false);
game->mark_board(5);
REQUIRE(game->game_over() == false);
game->mark_board(3);
REQUIRE(game->game_over() == false);
game->mark_board(9);
REQUIRE(game->game_over() == false);
game->mark_board(6);
REQUIRE(game->game_over() == false);
game->mark_board(13);
REQUIRE(game->game_over() == true);
REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by second column 4") {
unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
game->start_game("X");
game->mark_board(2);
REQUIRE(game->game_over() == false);
game->mark_board(5);
REQUIRE(game->game_over() == false);
game->mark_board(6);
REQUIRE(game->game_over() == false);
game->mark_board(9);
REQUIRE(game->game_over() == false);
game->mark_board(10);
REQUIRE(game->game_over() == false);
game->mark_board(13);
REQUIRE(game->game_over() == false);
game->mark_board(14);
REQUIRE(game->game_over() == true);
REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by third column 4") {
unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
game->start_game("X");
game->mark_board(3);
REQUIRE(game->game_over() == false);
game->mark_board(6);
REQUIRE(game->game_over() == false);
game->mark_board(7);
REQUIRE(game->game_over() == false);
game->mark_board(10);
REQUIRE(game->game_over() == false);
game->mark_board(11);
REQUIRE(game->game_over() == false);
game->mark_board(1);
REQUIRE(game->game_over() == false);
game->mark_board(15);
REQUIRE(game->game_over() == true);
REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by fourth column 4") {
unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
game->start_game("X");
game->mark_board(4);
REQUIRE(game->game_over() == false);
game->mark_board(7);
REQUIRE(game->game_over() == false);
game->mark_board(8);
REQUIRE(game->game_over() == false);
game->mark_board(10);
REQUIRE(game->game_over() == false);
game->mark_board(12);
REQUIRE(game->game_over() == false);
game->mark_board(1);
REQUIRE(game->game_over() == false);
game->mark_board(16);
REQUIRE(game->game_over() == true);
REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by first row 4") {
unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
game->start_game("X");
game->mark_board(1);
REQUIRE(game->game_over() == false);
game->mark_board(5);
REQUIRE(game->game_over() == false);
game->mark_board(2);
REQUIRE(game->game_over() == false);
game->mark_board(9);
REQUIRE(game->game_over() == false);
game->mark_board(3);
REQUIRE(game->game_over() == false);
game->mark_board(6);
REQUIRE(game->game_over() == false);
game->mark_board(4);
REQUIRE(game->game_over() == true);
REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by second row 4") {
unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
game->start_game("X");
game->mark_board(5);
REQUIRE(game->game_over() == false);
game->mark_board(2);
REQUIRE(game->game_over() == false);
game->mark_board(6);
REQUIRE(game->game_over() == false);
game->mark_board(9);
REQUIRE(game->game_over() == false);
game->mark_board(7);
REQUIRE(game->game_over() == false);
game->mark_board(3);
REQUIRE(game->game_over() == false);
game->mark_board(8);
REQUIRE(game->game_over() == true);
REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by third row 4") {
unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
game->start_game("X");
game->mark_board(9);
REQUIRE(game->game_over() == false);
game->mark_board(5);
REQUIRE(game->game_over() == false);
game->mark_board(10);
REQUIRE(game->game_over() == false);
game->mark_board(1);
REQUIRE(game->game_over() == false);
game->mark_board(11);
REQUIRE(game->game_over() == false);
game->mark_board(6);
REQUIRE(game->game_over() == false);
game->mark_board(12);
REQUIRE(game->game_over() == true);
REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by fourth row 4") {
unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
game->start_game("X");
game->mark_board(13);
REQUIRE(game->game_over() == false);
game->mark_board(5);
REQUIRE(game->game_over() == false);
game->mark_board(14);
REQUIRE(game->game_over() == false);
game->mark_board(1);
REQUIRE(game->game_over() == false);
game->mark_board(15);
REQUIRE(game->game_over() == false);
game->mark_board(6);
REQUIRE(game->game_over() == false);
game->mark_board(16);
REQUIRE(game->game_over() == true);
REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win diagonally from top left 4") {
unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
game->start_game("X");
game->mark_board(1);
REQUIRE(game->game_over() == false);
game->mark_board(2);
REQUIRE(game->game_over() == false);
game->mark_board(6);
REQUIRE(game->game_over() == false);
game->mark_board(5);
REQUIRE(game->game_over() == false);
game->mark_board(11);
REQUIRE(game->game_over() == false);
game->mark_board(4);
REQUIRE(game->game_over() == false);
game->mark_board(16);
REQUIRE(game->game_over() == true);
REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win diagonally from bottom left 4") {
unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
game->start_game("X");
game->mark_board(13);
REQUIRE(game->game_over() == false);
game->mark_board(2);
REQUIRE(game->game_over() == false);
game->mark_board(10);
REQUIRE(game->game_over() == false);
game->mark_board(1);
REQUIRE(game->game_over() == false);
game->mark_board(7);
REQUIRE(game->game_over() == false);
game->mark_board(11);
REQUIRE(game->game_over() == false);
game->mark_board(4);
REQUIRE(game->game_over() == true);
REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test TicTacToe manager get winner total function 4") {
int o, w, t; // X, O, and tie totals

TicTacToeManager manager;
unique_ptr<TicTacToe> game1 = make_unique<TicTacToe4>();
game1->start_game("X");
game1->mark_board(13);
REQUIRE(game1->game_over() == false);
game1->mark_board(5);
REQUIRE(game1->game_over() == false);
game1->mark_board(14);
REQUIRE(game1->game_over() == false);
game1->mark_board(1);
REQUIRE(game1->game_over() == false);
game1->mark_board(15);
REQUIRE(game1->game_over() == false);
game1->mark_board(6);
REQUIRE(game1->game_over() == false);
game1->mark_board(16);
REQUIRE(game1->game_over() == true);
REQUIRE(game1->get_winner() == "X");
manager.save_game(game1);
// End game1
unique_ptr<TicTacToe> game2 = make_unique<TicTacToe4>();
game2->start_game("X");
game2->mark_board(1);
REQUIRE(game2->game_over() == false);
game2->mark_board(3);
REQUIRE(game2->game_over() == false);
game2->mark_board(2);
REQUIRE(game2->game_over() == false);
game2->mark_board(4);
REQUIRE(game2->game_over() == false);
game2->mark_board(6);
REQUIRE(game2->game_over() == false);
game2->mark_board(5);
REQUIRE(game2->game_over() == false);
game2->mark_board(7);
REQUIRE(game2->game_over() == false);
game2->mark_board(8);
REQUIRE(game2->game_over() == false);
game2->mark_board(9);
REQUIRE(game2->game_over() == false);
game2->mark_board(10);
REQUIRE(game2->game_over() == false);
game2->mark_board(11);
REQUIRE(game2->game_over() == false);
game2->mark_board(16);
REQUIRE(game2->game_over() == false);
game2->mark_board(12);
REQUIRE(game2->game_over() == false);
game2->mark_board(13);
REQUIRE(game2->game_over() == false);
game2->mark_board(14);
REQUIRE(game2->game_over() == false);
game2->mark_board(15);
REQUIRE(game2->game_over() == true);
REQUIRE(game2->get_winner() == "C");
manager.save_game(game2);
// End game2
unique_ptr<TicTacToe> game3 = make_unique<TicTacToe4>();
game3->start_game("O");
game3->mark_board(13);
REQUIRE(game3->game_over() == false);
game3->mark_board(2);
REQUIRE(game3->game_over() == false);
game3->mark_board(10);
REQUIRE(game3->game_over() == false);
game3->mark_board(1);
REQUIRE(game3->game_over() == false);
game3->mark_board(7);
REQUIRE(game3->game_over() == false);
game3->mark_board(11);
REQUIRE(game3->game_over() == false);
game3->mark_board(4);
REQUIRE(game3->game_over() == true);
REQUIRE(game3->get_winner() == "O");
manager.save_game(game3);
// End game 3

manager.get_winner_total(o,w,t);
REQUIRE(o == 1);
REQUIRE(w == 1);
REQUIRE(t == 1);
}