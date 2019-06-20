#include "libs.h"
#ifndef ADMIRAL_H
#define ADMIRAL_H
struct Admiral
{
    int fleet_size=0;
    char attack_board[10][10];
    char defend_board[10][10];
    void set_battleships(int c,char defend_board[10][10]);
    void shot_battleships(char attack_board[10][10],char defend_board[10][10]);
};
#endif // ADMIRAL_H
