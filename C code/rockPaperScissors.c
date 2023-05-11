#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_choice, computer_choice, result;
    srand(time(NULL));  // seed the random number generator with the current time

    printf("Welcome to Rock-Paper-Scissors!\n");

    while (1) {
        // get the player's choice
        printf("\nEnter your choice (1 = rock, 2 = paper, 3 = scissors): ");
        scanf("%d", &player_choice);

        // check if the player's choice is valid
        if (player_choice < 1 || player_choice > 3) {
            printf("Invalid choice! Please try again.\n");
            continue;
        }

        // generate the computer's choice
        computer_choice = rand() % 3 + 1;

        // print the player's and computer's choices
        printf("You chose ");
        switch (player_choice) {
        case 1:
            printf("rock");
            break;
        case 2:
            printf("paper");
            break;
        case 3:
            printf("scissors");
            break;
        }
        printf(", and the computer chose ");
        switch (computer_choice) {
        case 1:
            printf("rock");
            break;
        case 2:
            printf("paper");
            break;
        case 3:
            printf("scissors");
            break;
        }
        printf(".\n");

        // determine the result of the game
        if (player_choice == computer_choice) {
            printf("It's a tie!\n");
            result = 0;
        }
        else if ((player_choice == 1 && computer_choice == 3) ||
            (player_choice == 2 && computer_choice == 1) ||
            (player_choice == 3 && computer_choice == 2)) {
            printf("You win!\n");
            result = 1;
        }
        else {
            printf("You lose!\n");
            result = -1;
        }

        // ask the player if they want to play again
        printf("Do you want to play again? (y/n): ");
        char response;
        scanf(" %c", &response);
        if (response != 'y' && response != 'Y') {
            break;
        }
    }

    return 0;
}
