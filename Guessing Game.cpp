#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <string>

using namespace std;

// Function prototypes
void displayInstructions(const string& diff);
void clearInput();
int getValidGuess(const string& diff);
int updateHighScore(int score, int high_score);

int main() {
    srand(time(0));
    string diff;
    int score;
    int high_score = INT_MAX;

    while (true) {
        score = 0;

        cout << "What difficulty would you like? (easy, medium, or hard)" << endl;
        cin >> diff;
        clearInput();
        
        int randnum;
        // Determine random number based on difficulty
        if (diff == "easy") {
            randnum = rand() % 100 + 1;
        } else if (diff == "medium") {
            randnum = rand() % 1000 + 1;
        } else if (diff == "hard") { 
            randnum = rand() % 10000 + 1;
        } else {
            cout << "Invalid difficulty. Please choose 'easy', 'medium', or 'hard'." << endl;
            continue; // Restart the loop
        }

        displayInstructions(diff);

        // Game loop for guessing
        while (true) {
            int guess = getValidGuess(diff);

            if (guess == randnum) {
                cout << "Correct! " << guess << " was the correct number!" << endl;
                break; // Exit loop
            } else if (guess > randnum) {
                cout << "Incorrect. Your guess of " << guess << " was too high!" << endl;
                score++;
            } else {
                cout << "Incorrect. Your guess of " << guess << " was too low!" << endl;
                score++;
            }
        }

        // Update and display the scores
        cout << "Your score was: " << score << endl;
        high_score = updateHighScore(score, high_score);
        cout << "High score: " << high_score << endl;

        // Ask if the player wants to play again
        char playagain;
        cout << "Would you like to play again? (Y/N): ";
        cin >> playagain;
        clearInput();

        if (playagain != 'Y' && playagain != 'y') {
            break; // Exit the main game loop
        }
    }
    return 0;
}

// Function implementations
void displayInstructions(const string& diff) {
    if (diff == "easy") {
        cout << "Try guessing a number between 1 - 100 that I have already chosen: " << endl;
    } else if (diff == "medium") {
        cout << "Try guessing a number between 1 - 1000 that I have already chosen: " << endl;
    } else if (diff == "hard") {
        cout << "Try guessing a number between 1 - 10000 that I have already chosen: " << endl;
    }
}

void clearInput() {
    cin.clear();
    cin.ignore(INT_MAX, '\n');
}

int getValidGuess(const string& diff) {
    int guess;
    while (true) {
        cin >> guess;
        if (cin.fail()) {
            clearInput();
            cout << "Invalid input. Please enter a number." << endl;
        } else if ((diff == "easy" && (guess < 1 || guess > 100)) ||
                   (diff == "medium" && (guess < 1 || guess > 1000)) ||
                   (diff == "hard" && (guess < 1 || guess > 10000))) {
            clearInput();
            cout << "Invalid input. Please enter a number within the range." << endl;
        } else {
            clearInput();
            return guess;
        }
    }
}

int updateHighScore(int score, int high_score) {
    if (score < high_score) {
        return score; // New high score
    } else {
        return high_score; // Previous high score remains
    }
}
