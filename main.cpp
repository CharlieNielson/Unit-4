#include <iostream>
#include <time.h>
#include "Die.h"
using namespace std;


int main() {
    srand(time(NULL));  //Set the random seed
    //Declare die
    int sides = 6;
    if (true) {
        Die d1(1);
        d1.roll();
        d1.display();
    }
    Die d1(6);
    d1.roll();
    d1.display();
    if (d1.getDieValue() == 1) {
        cout << "Doubles!\n";
    }
    while (sides > 0) {
        cout << "How many sides for your dice(0 for quit): ";
        cin >> sides;
        cout << endl;
        if (sides != 0) {
            Die d1(sides);
            //Call methods
            d1.roll();
            d1.display();
        }
    }
}

