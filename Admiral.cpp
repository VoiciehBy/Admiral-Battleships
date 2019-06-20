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
