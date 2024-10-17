#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printWelcomeMessage()
{
    cout << "========================================\n";
    cout << "         Welcome to Final Brain Cell!   \n";
    cout << "========================================\n";
    cout << "Guess the number before you lose all your brain cells!\n\n";
}

int generateRandomNumber(int maxNumber)
{
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator
    return rand() % maxNumber + 1;             // Random number between 1 and maxNumber
}

void chooseDifficulty(int &maxNumber, int &attemptsLeft)
{
    int choice;
    cout << "Choose your difficulty level:\n";
    cout << "1. Easy (Number between 1 and 10, 7 attempts)\n";
    cout << "2. Medium (Number between 1 and 20, 5 attempts)\n";
    cout << "3. Hard (Number between 1 and 50, 3 attempts)\n";
    cout << "Enter your choice (1, 2, or 3): ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        maxNumber = 10;
        attemptsLeft = 7;
        break;
    case 2:
        maxNumber = 20;
        attemptsLeft = 5;
        break;
    case 3:
        maxNumber = 50;
        attemptsLeft = 3;
        break;
    default:
        cout << "Invalid choice. Defaulting to Medium difficulty.\n";
        maxNumber = 50;
        attemptsLeft = 5;
    }
}

int calculateScore(int attemptsLeft, int maxAttempts)
{
    return (attemptsLeft * 100) / maxAttempts;
}

int main()
{
    printWelcomeMessage();

    int maxNumber;
    int attemptsLeft;
    chooseDifficulty(maxNumber, attemptsLeft);

    int maxAttempts = attemptsLeft; // Store the initial number of attempts for scoring
    int secretNumber = generateRandomNumber(maxNumber);
    int guess;

    while (attemptsLeft > 0)
    {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess == secretNumber)
        {
            cout << "Congratulations! You've guessed the correct number!\n";
            int score = calculateScore(attemptsLeft, maxAttempts);
            cout << "Your score: " << score << " points\n";
            break;
        }
        else if (guess < secretNumber)
        {
            cout << "Too low! You lost a brain cell.\n";
        }
        else
        {
            cout << "Too high! You lost a brain cell.\n";
        }

        attemptsLeft--;

        if (attemptsLeft > 0)
        {
            cout << "You have " << attemptsLeft << " brain cells left.\n";
        }
        else
        {
            cout << "Oh no! You've lost all your brain cells!\n";
            cout << "The correct number was: " << secretNumber << "\n";
            cout << "Your score: 0 points\n";
        }
    }

    cout << "Game Over! Thanks for playing Final Brain Cell.\n";

    return 0;
}
