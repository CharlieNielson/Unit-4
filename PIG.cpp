#include <iostream>
#include <time.h>
#include "pigPlay.h"
using namespace std;

int main() {
    srand(time(NULL));  //Set the random seed
    cout << "The game of PIG!\n";
    play player, computer;
    int playCont = 0;
    bool playTurn = true;
    while (player.getTotal() < 100 && computer.getTotal() < 100) {
        if (playTurn && player.getTotal() < 100 && computer.getTotal() < 100) {// Players turn
            player.startTurn();
            while (player.getDieValue() > 1) {
                cout << "Turn score : " << player.getTurnTotal() << "\nPlayers counted score: " << player.getTotal() << "\nComputers counted score: " << computer.getTotal() << "\n1. Roll\n2. Bag points\n";
                playCont = 0;
                while (playCont != 1 && playCont != 2) {
                    cin >> playCont;
                    cout << endl;
                    if (playCont != 1 && playCont != 2) {
                        cout << "Invalid response, try again.\n1. Roll\n2. Bag points\n";
                    }
                }
                if (playCont == 2) {
                    player.stop(true);
                } else {
                    player.roll(true);
                    cout << "You rolled a " << player.getDieValue() << endl;
                }
                
            }
            playTurn = false;
            cout << endl;
        } else if (player.getTotal() < 100 && computer.getTotal() < 100) {// Computer's turn.
            computer.startTurn();
            while (computer.getDieValue() > 1 && playTurn == false) {
                if (computer.getTurnTotal() < 20) {
                    computer.roll(false);
                } else {
                    computer.stop(false);
                    playTurn = true;
                }
                if (computer.getDieValue() <= 1) {
                    playTurn = true;
                }
            }
        }
    }
    if (computer.getTotal() > player.getTotal()) {
        cout << "Sorry, you have lost." << endl;
    } else {
        cout << "Congratulations! You have won!";
    }

    return 0;
}
