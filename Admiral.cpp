#include "Admiral.h"

Admiral::Admiral(int f_s, int is_p) : fleet_size(f_s),is_player(is_p) {
    attack_board = new char*[boardX];
    defend_board = new char*[boardX];
    for(int i = 0; i < boardX; i++) {
        attack_board[i] = new char[boardY];
        defend_board[i] = new char[boardY];
        for(int j = 0; j < boardY; j++) {
            attack_board[i][j] = ' ';
            defend_board[i][j] = ' ';
        }
    }
}

void Admiral::set_battleships(int c) {
    int x = 0,y = 0;
    for(int i = 0; i < c; i++) {
        int a = x,b = y;
        srand(time(NULL));
        if(is_player == 0) {
            while( (x == a && y == b)  || x == 0 ||  y == 0 || x>10 || y>10 ) {
                display_defend_board();
                x = rand() % 10;
                y = rand() % 10;
            }
            println( "COM x: ",x );
            println( "COM y: ",y);
        }

        else {
            println("Input coordinates:");
            cin >> x >> y;
            while( (x == a && y == b)  || x>10 || y>10 ) {
                println("Again,Input coordinates:");
                cin >> x >> y;
            }
        }
        defend_board[x-1][y-1] = 'U';
        display_defend_board();
    }
}

void Admiral::shot_battleships(int& enemy_fleet_size,char** enemy_defend_board) {
    int x = 0,y = 0;
    while(3 != 5) {
        int a = x,b = y;
        srand(time(NULL));
        if(is_player == 0) {
            while( (x == a && y == b)  || x == 0 ||  y == 0 || x>10 || y>10 ) {
                x = rand() % 10;
                y = rand() % 10;
            }
            println( "COM sh x: ",x);
            println( "COM sh y: ",y);
        }

        else {
            println("Input coordinates:");
            cin >> x >> y;
            while( (x == a && y == b) || x > 10 || y > 10 || x <= 0 || y <= 0) {
                println("Again,Input coordinates:");
                cin >> x >> y;
            }
        }
        if(enemy_defend_board[x-1][y-1] == 'U') {
            println("Down!");
            attack_board[x-1][y-1] = 'x';
            enemy_defend_board[x-1][y-1] = 'x';
            fleet_size--;
            if(fleet_size == 0) {
                println("Enemy lost!");
                break;
            }
        } else {
            println("Missed!");
            attack_board[x-1][y-1] = 'O';
            enemy_defend_board[x-1][y-1] = 'O';
            break;
        }
    }
}

void Admiral::display_attack_board() {
    if(is_player == 1) {
        int a = 10;
        for(int i = 0; i < a; i++) {
            for(int ii = 0; ii < 30; ii++)
                cout << '=';
            cout << endl
                 << '|' << attack_board[i][0] << '|';
            for(int j = 1; j<a; j++)
                cout << '|' << attack_board[i][j] << '|';
            breakLine();
        }
        for(int ii = 0; ii<30; ii++)
            cout << '=';
        breakLine();
    } else breakLine();
}

void Admiral::display_defend_board() {
    int a = 10;
    if(is_player == 1) {
        for(int i = 0; i < a; i++) {
            for(int ii = 0; ii < 30; ii++)
                cout << '=';
            cout << endl
                 << '|' << defend_board[i][0] << '|';
            for(int j = 1; j<a; j++)
                cout << '|' << defend_board[i][j] << '|';
            breakLine();
        }
        for(int ii = 0; ii<30; ii++)
            cout << '=';
        breakLine();
    } else breakLine();

}

Admiral::~Admiral() {
    for(int i = 0; i < boardX; i++) {
        for(int j = 0; j < boardY; j++) {
            attack_board[i][j] = ' ';
            defend_board[i][j] = ' ';
        }
    }
    delete attack_board;
    delete defend_board;
}
