#include <iostream>
#include "No Brainer Pokemon.h"
#include <time.h>
using namespace std;

pokemon::pokemon() {
    name = "Pikachu";
    hp = 100;
    strength = 0;
}

pokemon::pokemon(string name) {
    this -> name = name;
    hp = 100;
    strength = 0;
}

int pokemon::getStrength() {
    return strength;
}

string pokemon::getName() {
    return name;
}

int pokemon::getHP() {
    return hp;
}

void pokemon::setStrength() {
    this -> strength = rand() % 42 + 1;
}

void pokemon::takeDamage(int damage) {
    hp -= damage;
}

void pokemon::battle(pokemon &other) {
    this -> setStrength();
    other.setStrength();

    if (strength >= other.getStrength()) {
        int damage = strength - other.getStrength();
        other.takeDamage(damage);
    } else {
        int damage = other.getStrength() - strength;
        this -> takeDamage(damage);
    }
}

ostream& operator << (ostream &out, pokemon p) {
    out << setw(10) << p.name << ": " << setw(12);

    for (int i = 0; i < 100; i += 5) {
        if (i <= p.hp) {
            out << "#";
        } else {
            out << "_";
        }
    }
    cout << endl;
    return out;
}

int main() {
    srand(time(NULL));
    cout << "Pokemon Battle!\n";

    string name;

    cout << "Enter your Pokemon's name: ";
    cin >> name;
    cout << endl;

    pokemon player(name);
    pokemon computer;

    int choice;

    while(choice != 2 && player.getHP() > 0 && computer.getHP() > 0) {
        cout << player;
        cout << computer;
        cout << "1. Battle\n2. Quit\n";
        cin >> choice;

        player.battle(computer);
    }

    if (player.getHP() > computer.getHP() && choice != 2) {
        cout << "You win!";
    } else {
        cout << "You lose.";
    }

    return 0;
}
