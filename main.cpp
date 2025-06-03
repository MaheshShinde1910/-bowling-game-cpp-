#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "BowlingGame.h"

using namespace std;

int main() {
    BowlingGame game;
    vector<int> rolls;
    int pins;
    
    cout << "Bowling Game Score Calculator" << endl;
    cout << "Enter the number of pins knocked down in each roll (21 max):" << endl;
    cout << "Enter -1 to finish input" << endl;
    
    while (true) {
        cout << "Roll " << (rolls.size() + 1) << ": ";
        cin >> pins;
        
        if (pins == -1) break;
        if (pins < 0 || pins > 10) {
            cout << "Invalid input. Pins must be between 0 and 10." << endl;
            continue;
        }
        
        rolls.push_back(pins);
        if (rolls.size() >= 21) break;
    }
    
    for (int roll : rolls) {
        game.roll(roll);
    }
    
    cout << "Total Score: " << game.score() << endl;
    
    return 0;
}
