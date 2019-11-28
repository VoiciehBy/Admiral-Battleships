#include "libs.h"
#include "utility.h"
#include "Admiral.h"
Admiral player;
Admiral player1;

void start_game()
{
    cout << "BATTLESHIPS" << endl;
    cout << "   ___" << endl;
    cout << "Enter size of your fleet:" << endl;
    cin >> player.fleet_size;
    player1.fleet_size=player.fleet_size;
    cout << "Your fleet: " << player.fleet_size
         << " ships ready to fight!!!" << endl;
}

int main()
{
    start_game();
    char board[10][10];
    char board1[10][10];
    char board2[10][10];
    char board3[10][10];
    player.create_empty_board(board);
    player.create_empty_board(board1);
    player1.create_empty_board(board2);
    player1.create_empty_board(board3);
    cout << "PS moves ships:" << endl;
    player.set_battleships(player.fleet_size,board);
    player.display_board(board);
    pause_n_clear();


    cout << "COM moves ships:" << endl;
    player1.set_battleships(player1.fleet_size,board2);
    player1.display_board(board2);

    pause_n_clear();

    while(player.fleet_size!=0 && player1.fleet_size!=0)
    {
        cout << "PS:" << endl;
        player.display_board(board);
        player.display_board(board1);

        cout << "PS TURN:" << endl;
        player.shot_battleships(board1,board2);
        player.display_board(board1);
        if(player.fleet_size==0)
        {
            cout << "COM lost!" << endl;
            return 0;
        }

        pause_n_clear();

        cout << "COM:" << endl;
        player.display_board(board2);
        player1.display_board(board3);
        cout << "COM TURN:" << endl;
        player1.shot_battleships(board3,board);
        player1.display_board(board3);
        if(player.fleet_size==0)
        {
            cout << "PS lost!" << endl;
            return 0;
        }

        pause_n_clear();

    }
}
