#include "BowlingGame.h"
#include <stdexcept>

BowlingGame::BowlingGame() {
    rolls.resize(21, 0);
}

void BowlingGame::roll(int pins) {
    if (pins < 0 || pins > 10)
        throw std::invalid_argument("Pins must be 0-10");
    rolls[currentRoll++] = pins;
}

bool BowlingGame::isStrike(int frameIndex) {
    return rolls[frameIndex] == 10;
}

bool BowlingGame::isSpare(int frameIndex) {
    return rolls[frameIndex] + rolls[frameIndex+1] == 10;
}

int BowlingGame::strikeBonus(int frameIndex) {
    return rolls[frameIndex+1] + rolls[frameIndex+2];
}

int BowlingGame::spareBonus(int frameIndex) {
    return rolls[frameIndex+2];
}

int BowlingGame::score() {
    int score = 0;
    int frameIndex = 0;
    
    for (int frame = 0; frame < 10; frame++) {
        if (frame == 9) { // 10th frame
            score += rolls[frameIndex] + rolls[frameIndex+1];
            if (isStrike(frameIndex) || isSpare(frameIndex))
                score += rolls[frameIndex+2];
        }
        else if (isStrike(frameIndex)) {
            score += 10 + strikeBonus(frameIndex);
            frameIndex++;
        }
        else if (isSpare(frameIndex)) {
            score += 10 + spareBonus(frameIndex);
            frameIndex += 2;
        }
        else {
            score += rolls[frameIndex] + rolls[frameIndex+1];
            frameIndex += 2;
        }
    }
    
    return score;
}
