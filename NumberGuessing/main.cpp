//
//  main.cpp
//  NumberGuessing
//
//  Created by Jeremy Greer on 5/6/17.
//  Copyright © 2017 Grizzle. All rights reserved.
//
/*
 This will randomly pick a number and ask you to guess.  It will tell you if your guess is over or under the number.
 It will tell you how many attempts you took.
 */

#include <iostream>

int getRandomInt(int max) {
    // Seed randomizer so values will be unique each time.
    srand(static_cast<unsigned int>(time(NULL)));
    return rand() % max;
}

int getGuess(int guessCount) {
    std::cout << "#" << (guessCount + 1) << ": ";
    int guess;
    std::cin >> guess;
    return guess;
}

void win(int guessCount) {
    std::cout << "You got it in " << guessCount << " guesses." << std::endl;
}

void hint(int guess, int secretNumber) {
    if (guess < secretNumber) {
        std::cout << "too low";
    } else {
       std::cout << "too high";
    }
    std::cout << std::endl;
}

bool playAgain() {
    int input;
    std::cout << "Again (0 - no, 1 - yes)? ";
    std::cin >> input;
    return input == 1;
}

int main(int argc, const char * argv[]) {
    int max = 33;
    int secretNumber = getRandomInt(max);
    int guessCount = 0;
    
    while (1) {
        int guess = getGuess(guessCount);
        guessCount += 1;
        if (guess == secretNumber) {
            win(guessCount);
            if (!playAgain()) {
                break;
            }
            secretNumber = getRandomInt(max);
            guessCount = 0;
        } else {
            hint(guess, secretNumber);
        }
    }
    
    return 0;
}
