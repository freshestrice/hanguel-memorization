#include <iostream>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For seeding random
#include <map>     // For character-to-sound mapping
using namespace std;

void displayMenu() {
    system("cls");
    cout << "Choose a game mode:\n1. Vowels\n2. Consonants\n3. Both\n4. Exit\nPlease enter the number of your choice: ";
}

// Function to display the rules
void displayRules() {
    system("cls");
    cout << "\nRules:\n1. You will be shown a Korean character.\n2. Type the corresponding sound (e.g., 'ㅏ' -> 'a').\n3. Each correct answer gives +10 points.\n4. Incorrect answers reset your score to 0.\n5. You can exit anytime by typing 'exit'.\n\n";
}

// Function to handle the game
void playGame(const map<string, string>& characterMap) {
    int score = 0, highScore = 0;
    string userAnswer;

    srand(time(0)); // Seed the random number generator

    while (true) {
        // Select a random character
        auto it = characterMap.begin();
        advance(it, rand() % characterMap.size());
        string koreanChar = it->first;
        string correctSound = it->second;

        cout << "\nWhat is the sound for '" << koreanChar << "'? (Type 'exit' to quit): ";
        cin >> userAnswer;

        if (userAnswer == "exit") {
            break;
        }

        if (userAnswer == correctSound) {
            score += 10;
            if (score > highScore) highScore = score;
            cout << "Correct! Your score: " << score << " | High Score: " << highScore << endl;
        } else {
            cout << "Incorrect. The correct answer was '" << correctSound << "'.\n";
            score = 0;
            cout << "Your score has been reset.\n";
        }
    }
}

int main() {
    system("chcp 65001 > nul");
    system("chcp 65001 > nul");

    // Korean characters and their sounds
    map<string, string> vowels = {
        {"ㅛ", "yo"}, {"ㅕ", "yeo"}, {"ㅑ", "ya"}, {"ㅐ", "ea"}, {"ㅔ", "eh"},
        {"ㅗ", "o"}, {"ㅓ", "eo"}, {"ㅏ", "a"}, {"ㅣ", "i"}, {"ㅠ", "yu"},
        {"ㅜ", "u"}, {"ㅡ", "eu"}};

    map<string, string> consonants = {
        {"ㅂ", "b"}, {"ㅈ", "j"}, {"ㄷ", "d"}, {"ㄱ", "g"}, {"ㅅ", "s"}, 
        {"ㅁ", "m"}, {"ㄴ", "n"}, {"ㅇ", "o"}, {"ㄹ", "r"}, {"ㅎ", "h"}, 
        {"ㅋ", "k"}, {"ㅌ", "t"}, {"ㅊ", "ch"}, {"ㅍ", "p"}};

    map<string, string> allCharacters = vowels;
    allCharacters.insert(consonants.begin(), consonants.end());

    int userChoice;

    while (true) {
        system("cls"); // Clear the screen
        cout << "1. Play\n2. Rules\n3. Exit\nPlease enter the number of your choice: ";
        cin >> userChoice;

        if (userChoice == 1) {
            displayMenu();
            cin >> userChoice;

            if (userChoice == 1) {
                playGame(vowels);
            } else if (userChoice == 2) {
                playGame(consonants);
            } else if (userChoice == 3) {
                playGame(allCharacters);
            } else if (userChoice == 4) {
                break;
            } else {
                cout << "Invalid choice. Please try again.\n";
            }
        } else if (userChoice == 2) {
            displayRules();
        } else if (userChoice == 3) {
            cout << "Thank you for playing! Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 3.\n";
        }
    }

    return 0;
}
