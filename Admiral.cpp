#include "Admiral.h"
void Admiral::set_battleships(int c,char defend_board[10][10])
{
    int x=0,y=0;
    for(int i=0; i<c; i++)
    {
        int a=x,b=y;
        cout << "Input cordinates:" << endl;
        cin >> x >> y;
        while(x==a && y==b)
        {
            cout << "Again,Input cordinates:" << endl;
            cin >> x >> y;
        }
        defend_board[x-1][y-1]='U';
    }
}

void Admiral::shot_battleships(char attack_board[10][10],char defend_board[10][10])
{
    int x=0,y=0;
    while(3!=5)
    {
        int a=x,b=y;
        cout << "Input cordinates:" << endl;
        cin >> x >> y;
        while(x==a && y==b)
        {
            cout << "Again,Input cordinates:" << endl;
            cin >> x >> y;
        }
        if(defend_board[x-1][y-1]=='U')
        {
            cout << "Down!" << endl;
            attack_board[x-1][y-1]='x';
            defend_board[x-1][y-1]='x';
            fleet_size--;
            if(fleet_size==0)
            {
                cout << "Enemy lost!" << endl;
                break;
            }
        }
        else
        {
            cout << "Missed!" << endl;
            attack_board[x-1][y-1]='O';
            defend_board[x-1][y-1]='O';
            break;
        }
    }
}

void Admiral::display_board(char board[10][10])
{
    int a=10;
    for(int i=0; i<a; i++)
    {
        for(int ii=0; ii<30; ii++)
            cout << '=';
        cout << endl
             << '|' << board[i][0] << '|';
        for(int j=1; j<a; j++)
            cout << '|' << board[i][j] << '|';
        cout << endl;
    }
    for(int ii=0; ii<30; ii++)
        cout << '=';
    cout << endl;
}

void Admiral::create_empty_board(char board[10][10])
{
    int a=10;
    for(int i=0; i<a; i++)
    {
        board[i][0]=' ';
        for(int j=0; j<a; j++)
            board[i][j]=' ';
    }
}
