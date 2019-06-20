#include "libs.h"
#include "Admiral.h"
Admiral player;
Admiral player1;
void display_board(char board[10][10])
{
    int a=10;
    for(int i=0; i<a; i++)
    {
        for(int ii=0; ii<30; ii++)
            cout << '=';
        cout << endl;
        cout << '|' << board[i][0] << '|';
        for(int j=1; j<a; j++)
        {
            cout << '|' << board[i][j] << '|';
        }
        cout << endl;
    }
    for(int ii=0; ii<30; ii++)
        cout << '=';
    cout << endl;
}

void create_empty_board(char board[10][10])
{
    int a=10;
    for(int i=0; i<a; i++)
    {
        board[i][0]=' ';
        for(int j=0; j<a; j++)
            board[i][j]=' ';
    }
}

void pause_n_clear()
{
#ifdef _WIN32
    system("PAUSE");
    system("CLS");
#elif __gnu_linux
    system("echo Press any key to continue");
    system("read -p ... .");
    system("clear");
#elif __APPLE__
    system("echo Press any key to continue");
    system("read -p ... .");
    system("clear");
#else
    cout << "OS not supported!" << endl;
#endif
}

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
    create_empty_board(board);
    create_empty_board(board1);
    create_empty_board(board2);
    create_empty_board(board3);
    cout << "PS moves ships:" << endl;
    player.set_battleships(player.fleet_size,board);
    display_board(board);
    pause_n_clear();


    cout << "COM moves ships:" << endl;
    player1.set_battleships(player1.fleet_size,board2);
    display_board(board2);

    pause_n_clear();

    while(player.fleet_size!=0 && player1.fleet_size!=0)
    {
        cout << "PS:" << endl;
        display_board(board);
        display_board(board1);

        cout << "PS TURN:" << endl;
        player.shot_battleships(board1,board2);
        display_board(board1);
        if(player.fleet_size==0)
        {
            cout << "COM lost!" << endl;
            return 0;
        }

        pause_n_clear();

        cout << "COM:" << endl;
        display_board(board2);
        display_board(board3);
        cout << "COM TURN:" << endl;
        player1.shot_battleships(board3,board);
        display_board(board3);
        if(player.fleet_size==0)
        {
            cout << "PS lost!" << endl;
            return 0;
        }

        pause_n_clear();

    }
}
