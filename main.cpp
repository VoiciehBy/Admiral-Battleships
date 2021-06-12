#include "libs.h"
#include "utility.h"
#include "Admiral.h"
Admiral player(0,1);
Admiral player1(0,0);

void start_game() {
    cout << "BATTLESHIPS" << endl
         << "   ___" << endl
         << "Enter size of your fleet:";
    cin >> player.fleet_size;
    player1.fleet_size = player.fleet_size;
    cout << "Your fleet: " << player.fleet_size
         << " ships ready to fight!!!" << endl;
}

int main() {
    start_game();
    println("PS moves ships:");
    player.set_battleships(player.fleet_size);
    pause_n_clear();

    println("COM moves ships:");
    player1.set_battleships(player1.fleet_size);
    pause_n_clear();

    while(player.fleet_size != 0 && player1.fleet_size != 0) {
        println("PS:");
        player.display_defend_board();

        println("PS TURN:");
        player.display_attack_board();
        player.shot_battleships(player1.fleet_size,player1.defend_board);
        if(player.fleet_size == 0) {
            println("COM lost!");
            return 0;
        }

        pause_n_clear();

        println("COM:");
        player1.display_defend_board();
        println("COM TURN:");
        player1.display_attack_board();
        player1.shot_battleships(player.fleet_size,player.defend_board);
        if(player.fleet_size == 0) {
            println("PS lost!");
            return 0;
        }
    }
}
