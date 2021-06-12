#include "libs.h"
#include "utility.h"

#ifndef ADMIRAL_H
#define ADMIRAL_H
struct Admiral {
    int fleet_size;
    int is_player;
    int boardX=10;
    int boardY=10;
    char** attack_board;
    char** defend_board;

    Admiral(int = 0,int = 1);
    void set_battleships(int c);
    void shot_battleships(int& enemy_fleet_size,char** enemy_defend_board) ;
    void display_attack_board();
    void display_defend_board();

    ~Admiral();
};
#endif // ADMIRAL_H
