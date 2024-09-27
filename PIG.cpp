#include <iostream>
#include <time.h>
//#include "pigPlay.h"
using namespace std;

int main() {
    srand(time(NULL));  //Set the random seed
    cout << "The game of PIG!\n";
    int playerScore = 0;
    int computerScore = 0;
    int die = 6;
    int turnNUM = 0;
    int playCont = 0;
    bool playTurn = true;
    while (playerScore < 100 && computerScore < 100) {
        if (playTurn && playerScore < 100 && computerScore < 100) {// Players turn
            die = 6;
            turnNUM = 0;
            while (die > 1) {
                cout << "Turn score : " << turnNUM << "\nPlayers counted score: " << playerScore << "\nComputers counted score: " << computerScore << "\n1. Roll\n2. Bag points\n";
                playCont = 0;
                while (playCont != 1 && playCont != 2) {
                    cin >> playCont;
                    cout << endl;
                    if (playCont != 1 && playCont != 2) {
                        cout << "Invalid response, try again.\n1. Roll\n2. Bag points\n";
                    }
                }
                if (playCont == 2) {
                    playerScore += turnNUM;
                    die = -1;
                    cout << "Good choice. Your score is now " << playerScore << endl;
                } else {
                    die = (rand() % 6) + 1;
                    cout << "You rolled a " << die << endl;
                    if (die == 1) {
                        cout << "Sorry: you rolled a one. Your score will stay at " << playerScore << endl;
                    } else {
                        turnNUM += die;
                    }
                }
                
            }
            playTurn = false;
            cout << endl;
        } else if (playerScore < 100 && computerScore < 100) {// Computer's turn.
            die = 6;
            turnNUM = 0;
            while (die > 1 && playTurn == false) {
                if (turnNUM < 20) {
                    die = (rand() % 6) + 1;
                    if (die != 1) {
                        turnNUM += die;
                    }
                    cout << "Computer rolled a " << die << ". They have a turn score of " << turnNUM << endl;
                } else {
                    computerScore += turnNUM;
                    cout << "Computer bagged. Their score is now " << computerScore << endl << endl;
                    playTurn = true;
                }
            }
            if (playTurn != true) {
                cout << "Computers score will remain at " << computerScore << endl << endl;
                playTurn = true;
            }
        }
    }
    if (computerScore > playerScore) {
        cout << "Sorry, you have lost." << endl;
    } else {
        cout << "Congratulations! You have won!";
    }

    return 0;
}
