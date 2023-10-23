#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

int main() {
    std::cout << "Welcome to Rock-Paper-Scissors with a Twist!\n";
    std::cout << "Let's see if the computer can predict your moves.\n\n";

    std::vector<std::string> moves = {"Rock", "Paper", "Scissors"};
    int userScore = 0, computerScore = 0;
    int rounds = 5;  // You can change the number of rounds

    srand(time(0));

    for (int round = 1; round <= rounds; ++round) {
        int computerChoice = rand() % 3;
        int userChoice;

        std::cout << "Round " << round << "/" << rounds << std::endl;

        std::cout << "Enter your choice (0 for Rock, 1 for Paper, 2 for Scissors): ";
        std::cin >> userChoice;

        if (userChoice < 0 || userChoice > 2) {
            std::cout << "Invalid choice. Try again.\n";
            round--;
            continue;
        }

        std::cout << "You chose: " << moves[userChoice] << std::endl;
        std::cout << "Computer chose: " << moves[computerChoice] << std::endl;

        // Determine the winner and update scores
        if (userChoice == computerChoice) {
            std::cout << "It's a tie!\n";
        } else if ((userChoice == 0 && computerChoice == 2) ||
                   (userChoice == 1 && computerChoice == 0) ||
                   (userChoice == 2 && computerChoice == 1)) {
            std::cout << "You win this round!\n";
            userScore++;
        } else {
            std::cout << "Computer wins this round!\n";
            computerScore++;
        }

        std::cout << "Your Score: " << userScore << "  Computer Score: " << computerScore << "\n\n";
    }

    // Determine the overall winner
    std::cout << "Game Over!\n";
    if (userScore > computerScore) {
        std::cout << "Congratulations, you win!\n";
    } else if (computerScore > userScore) {
        std::cout << "Sorry, computer wins!\n";
    } else {
        std::cout << "It's a tie game!\n";
    }

    return 0;
}
