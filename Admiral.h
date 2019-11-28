#include "libs.h"

#ifndef ADMIRAL_H
#define ADMIRAL_H
struct Admiral
{
    int fleet_size;
    int is_player;

    Admiral(int = 0,int = 1);
    void set_battleships(int c,char defend_board[10][10]);
    void shot_battleships(char attack_board[10][10],char defend_board[10][10]);
    void display_board(char board[10][10]);
    void create_empty_board(char board[10][10]);
    ~Admiral();
};
#endif // ADMIRAL_H
