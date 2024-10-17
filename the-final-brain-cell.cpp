#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printWelcomeMessage() {
    cout << "========================================\n";
    cout << "         Welcome to Final Brain Cell!   \n";
    cout << "========================================\n";
    cout << "Guess the number (between 1 and 100) before you lose all your brain cells!\n";
    cout << "You have 5 brain cells left. Use them wisely!\n\n";
}

int generateRandomNumber() {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator
    return rand() % 10 + 1; // Random number between 1 and 100
}

int main() {
    printWelcomeMessage();

    int secretNumber = generateRandomNumber();
    int guess;
    int attemptsLeft = 5; // The player starts with 5 brain cells (attempts)

    while (attemptsLeft > 0) {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess == secretNumber) {
            cout << "Congratulations! You've guessed the correct number!\n";
            break;
        } else if (guess < secretNumber) {
            cout << "Too low! You lost a brain cell.\n";
        } else {
            cout << "Too high! You lost a brain cell.\n";
        }

        attemptsLeft--;

        if (attemptsLeft > 0) {
            cout << "You have " << attemptsLeft << " brain cells left.\n";
        } else {
            cout << "Oh no! You've lost all your brain cells!\n";
            cout << "The correct number was: " << secretNumber << "\n";
        }
    }

    cout << "Game Over! Thanks for playing Final Brain Cell.\n";

    return 0;
}
