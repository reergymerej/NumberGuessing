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

int getRandomInt() {
    return rand() % 100;
}

int getGuess() {
    std::cout << "? ";
    int guess;
    std::cin >> guess;
    return guess;
}

void win() {
    std::cout << "Correct";
}

void hint(int guess, int secretNumber) {
    if (guess < secretNumber) {
        std::cout << "too low";
    } else {
       std::cout << "too high";
    }
}

int main(int argc, const char * argv[]) {
    // pick a number
    int secretNumber = getRandomInt();
    while (1) {
        // prompt for guess
        int guess = getGuess();
        // determine if >, <, or ==
        if (guess == secretNumber) {
            win();
            break;
        } else {
            hint(guess, secretNumber);
        }
    }
    
    return 0;
}
