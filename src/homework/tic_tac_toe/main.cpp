#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

using std::string, std::cout, std::cin;
int main()
{
    // Instance Tic Tac Toe
    TicTacToe game;
    // Tic Tac Toe Manager instance
    TicTacToeManager manager;
    // declaration of variables
    string first_player;
    char choice;
    int o, w, t;

    do {
        cout << "Enter first player (X or O):";
        cin >> first_player;
        // Validate for correct input
        while (first_player != "X" && first_player != "O") {
            cout << "Invalid entry!\n";
            cout << "Entry must be an X or O.\n\n";
            cout << "Enter first player (X or O): ";
            cin >> first_player;
        }
        game.start_game(first_player);

        while (!game.game_over()) {
            cin >> game;
            cout << game;
        }

        cout << "\nThe winner is " << game.get_winner() << "!\n\n";  // Displays the winner
        manager.save_game(game);  // Win counter
        manager.get_winner_total(o, w, t); // Display running scores to the user
        cout << "Continue? Type y: "; // Ask user if they want to play another game
        cin >> choice;
        cout << "\n";

    } while (choice == 'Y'|| choice == 'y');
    cout << manager; // Displays all games played

    return 0;
}