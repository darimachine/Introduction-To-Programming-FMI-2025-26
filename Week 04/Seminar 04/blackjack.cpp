#include <cstdlib>
#include <ctime>
#include <iostream>

int randomBetween(int min, int max);
int drawCard();

int randomBetween(int min, int max) {
    return min + std::rand() % (max - min + 1);
}

int drawCard() {
    int card = randomBetween(1, 13);

    if (card > 10) {
        return 10;
    }

    return card;
}

int main() {
    std::srand(std::time(0));

    int firstCard = drawCard();
    int secondCard = drawCard();

    std::cout << "Your first card is " << firstCard << "." << std::endl;
    std::cout << "Your second card is " << secondCard << "." << std::endl;

    int playerPoints = firstCard + secondCard;
    int computerPoints = drawCard() + drawCard();

    bool playerStillPlaying = true;
    bool computerStillPlaying = true;

    while (playerStillPlaying || computerStillPlaying) {
        if (playerStillPlaying) {
            std::cout << std::endl;

            std::cout << "You have " << playerPoints << " points." << std::endl;
            std::cout << "Hit or Stand (H / S)? ";

            char choice;
            std::cin >> choice;

            if (choice == 'H' || choice == 'h') {
                int card = drawCard();
                std::cout << "You drew " << card << "." << std::endl;

                playerPoints += card;

                if (playerPoints > 21) {
                    std::cout << std::endl;
                    std::cout << "You broke 21 points. You lose!" << std::endl;
                    return 0;
                }
            } else {
                playerStillPlaying = false;
            }
        }

        if (computerStillPlaying) {
            std::cout << std::endl;

            if (computerPoints >= 18) {
                std::cout << "Dealer: I'll play with this hand." << std::endl;
                computerStillPlaying = false;
            } else {
                std::cout << "Dealer: I'll take another card." << std::endl;
                computerPoints += drawCard();
            }
        }
    }

    std::cout << std::endl;

    std::cout << "Dealer: I have " << computerPoints << " points. ";

    if (computerPoints > 21) {
        std::cout << "I broke 21, so you win!" << std::endl;
        return 0;
    }

    std::cout << "You have " << playerPoints << ". ";

    if (computerPoints > playerPoints) {
        std::cout << "You lose." << std::endl;
    } else if (playerPoints > computerPoints) {
        std::cout << "You win!" << std::endl;
    } else {
        std::cout << "It's a tie!" << std::endl;
    }

    return 0;
}
