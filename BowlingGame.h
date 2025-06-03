#ifndef BOWLINGGAME_H
#define BOWLINGGAME_H

#include <vector>

class BowlingGame {
private:
    std::vector<int> rolls;
    int currentRoll = 0;

    bool isStrike(int frameIndex);
    bool isSpare(int frameIndex);
    int sumOfBallsInFrame(int frameIndex);
    int strikeBonus(int frameIndex);
    int spareBonus(int frameIndex);

public:
    BowlingGame();
    void roll(int pins);
    int score();
};

#endif
