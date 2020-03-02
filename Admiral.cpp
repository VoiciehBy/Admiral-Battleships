#include "Admiral.h"

Admiral::Admiral(int f_s, int is_p) : fleet_size(f_s),is_player(is_p) {}

void Admiral::set_battleships(int c,char defend_board[10][10])
{
    int x = 0,y = 0;
    for(int i = 0; i < c; i++)
    {
        int a = x,b = y;
        srand(time(NULL));
        if(is_player == 0)
        {
            x = rand() % 10;
            cout << "COM x: " << x << endl;
            y = rand() % 10;
            cout << "COM y: " << y << endl;
        }

        else
        {
            cout << "Input coordinates:" << endl;
            cin >> x >> y;
            while( (x == a && y == b)  || x>10 || y>10 )
            {
                cout << "Again,Input coordinates:" << endl;
                cin >> x >> y;
            }
        }
        defend_board[x-1][y-1] = 'U';
    }
}

void Admiral::shot_battleships(char attack_board[10][10],char defend_board[10][10])
{
    int x = 0,y = 0;
    while(3 != 5)
    {
        int a = x,b = y;
        srand(time(NULL));
        if(is_player == 0)
        {
            x = rand() % 10;
            cout << "COM sh x: " << x << endl;
            y = rand() % 10;
            cout << "COM sh y: " << y << endl;
        }

        else
        {
            cout << "Input coordinates:" << endl;
            cin >> x >> y;
            while( (x == a && y == b) || x > 10 || y > 10 || x < 0 || y < 0)
            {
                cout << "Again,Input coordinates:" << endl;
                cin >> x >> y;
            }
        }
        if(defend_board[x-1][y-1] == 'U')
        {
            cout << "Down!" << endl;
            attack_board[x-1][y-1] = 'x';
            defend_board[x-1][y-1] = 'x';
            fleet_size--;
            if(fleet_size == 0)
            {
                cout << "Enemy lost!" << endl;
                break;
            }
        }
        else
        {
            cout << "Missed!" << endl;
            attack_board[x-1][y-1] = 'O';
            defend_board[x-1][y-1] = 'O';
            break;
        }
    }
}

void Admiral::display_board(char board[10][10])
{
    if(is_player == 1)
    {
        int a = 10;
        for(int i = 0; i < a; i++)
        {
            for(int ii = 0; ii < 30; ii++)
                cout << '=';
            cout << endl
                 << '|' << board[i][0] << '|';
            for(int j = 1; j<a; j++)
                cout << '|' << board[i][j] << '|';
            cout << endl;
        }
        for(int ii = 0; ii<30; ii++)
            cout << '=';
        cout << endl;
    }
    else
        cout << endl;
}

void Admiral::create_empty_board(char board[10][10])
{
    int a = 10;
    for(int i = 0; i < a; i++)
    {
        board[i][0] = ' ';
        for(int j = 0; j < a; j++)
            board[i][j] = ' ';
    }
}

Admiral::~Admiral() {}
