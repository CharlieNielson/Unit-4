#pragma once
#include <iostream>
using namespace std;

class PIG{
    public:
    PIG();
    void roll() {
       dieValue = rand() % 6 + 1;
    }
    int stop(int);
    int getValueDie() {
        return dieValue;
    }
    int getTurnTotal(int);
    int getTotal(int);

    private:
      int dieValue;
      int turnNUM;
      int gameTotal;
};

PIG::PIG() {
    srand(time(NULL));  //Set the random seed
    dieValue = rand() % 6 + 1;
    cout << "Thing: " << dieValue << endl;
}
