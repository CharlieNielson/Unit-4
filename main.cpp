#include <iostream>
#include <time.h>
#include "Die.h"
using namespace std;


int main() {
 srand(time(NULL));  //Set the random seed
 //Declare die
 Die d1(6);
 //Call methods
 d1.roll();
 d1.display();
}

