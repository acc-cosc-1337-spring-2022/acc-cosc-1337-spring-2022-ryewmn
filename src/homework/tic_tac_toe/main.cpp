#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include"tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"

using std::string, std::cout, std::cin;
int main()
{

    // Tic Tac Toe Manager instance
    unique_ptr<TicTacToe> game;
    // Create TicTacToeManager instance
    TicTacToeManager manager;
    // declaration of variables
    string first_player;
    char choice;
    int o, w, t;
    int gameChoice;

    do {
        // Prompt user for which TicTacToe game they want to play
        cout << "Would you like to play Tic Tac Toe 3 or 4?\n";
        cout << "Enter 3 or 4: ";
        cin >> gameChoice;
        // Validate for correct entry
        while (gameChoice != 3 && gameChoice != 4) {
            cout << "Invalid option\n";
            cout << "Would you like to play Tic Tac Toe 3 or 4?\n";
            cout << "Enter 3 or 4 : ";
            cin >> gameChoice;
        }
        // Create appropriate TicTacToe instance based off game choice
        if (gameChoice == 3) {
            game = make_unique<TicTacToe3>();
        } else {
            game = make_unique<TicTacToe4>();
        }
            cout << "Enter first player (X or O): ";
        cin >> first_player;
        // Validate for correct input
        while (first_player != "X" && first_player != "O") {
            cout << "Invalid entry!\n";
            cout << "Entry must be an X or O. \n\n";
            cout << "Enter first player (X or O): ";
            cin >> first_player;
        }
        game->start_game(first_player);

        while (!game->game_over()) {
            cin >> *game;
            cout << *game;
        }
        // Display winner of game
        cout << "\nThe winner is " << game->get_winner() << "!\n\n";

        // Add wins to TicTacToe Manager
        // Assignment states to dereference game for the following line,
        // but I receive an error when I do.
        manager.save_game(game);

        // Display running scores to the user
        manager.get_winner_total(o, w, t);

        // Ask user if they want to play another game
        cout << "Continue? Type y: ";
        cin >> choice;
        cout << "\n";


    } while (choice == 'Y'|| choice == 'y');
    cout << manager; // Displays all games played

    return 0;
}