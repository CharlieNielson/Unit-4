#pragma once
#include <iostream>
using namespace std;

class play {
    public:
        play();
        void roll(bool);
        void stop(bool);
        int getDieValue() { return dieValue; }
        int getTurnTotal() { return turnTotal; }
        int getTotal() { return gameTotal; }
        void startTurn() { dieValue = 6; }

    private:
        int dieValue;
        int turnTotal;
        int gameTotal;
};

play::play() {
    dieValue = rand() % 6 + 1;
    turnTotal = 0;
    gameTotal = 0;
}

void play::roll(bool playTurn) {
    dieValue = rand() % 6 + 1;
    if (playTurn) {
        cout << "You rolled a " << dieValue << ". your turn score is now " << turnTotal << endl;
    } else {
        cout << "Computer rolled a " << dieValue << ". They now have a turn score of " << turnTotal << endl;
    }
    if (dieValue == 1) {
        turnTotal = 0;
        if (playTurn) {
            cout << "Sorry: you rolled a one. Your score will stay at " << gameTotal << endl;
        } else {
            cout << "Computer rolled a one. Their score will remain at " << gameTotal << endl << endl;
        }
    } else {
        turnTotal += dieValue;
    }
}

void play::stop(bool playTurn) {
    gameTotal += turnTotal;
    if (playTurn) {
        cout << "Good choice. Your score is now " << gameTotal << endl;
    } else {
        cout << "Computer bagged. Their score is now " << gameTotal << endl << endl;
    }
    turnTotal = 0;
    dieValue = -1;
}
