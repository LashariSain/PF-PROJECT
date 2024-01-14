// Word Puzzle Game
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define MAX_WORD_LENGTH 15
#define MAX_ATTEMPTS 3

char words[][MAX_WORD_LENGTH + 1] = {"programming", "computer", "algorithm", "developer", "software","debugging","function","sucide","pointer","structure","loops"};

void shuffleLetters(char *word) {
    int i, j;
    int length = strlen(word);
    for (i = length - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        char temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }
}

void playWordPuzzleGame() {
    srand(time(NULL));
	
	int i,j;
    int score = 0;
     printf("\n\n\n\n\n\n\n\n\t\t _______________________________________________");
    printf("\n\t\t|*******WELCOME TO THE WORD PUZZLE GAME*******|");
    sleep(2);
	system("cls");
    printf("\n\n\n\n\n\n\n\n\n\t\t\tYOUR GAME STARTS IN ..... 3");
    sleep(1);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\t\t\tYOUR GAME STARTS IN ..... 2");
    sleep(1);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\t\t\tYOUR GAME STARTS IN ..... 1");
    sleep(1);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\t\t*******LET'S GO*******");
    sleep(1);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\t\tUnscramble the letters to form a meaningful word.");

    for ( i = 0; i < sizeof(words) / sizeof(words[0]); ++i) {
        int attempts = MAX_ATTEMPTS;

        char originalWord[MAX_WORD_LENGTH + 1];
        strcpy(originalWord, words[i]);

        char jumbledWord[MAX_WORD_LENGTH + 1];
        strcpy(jumbledWord, originalWord);
        shuffleLetters(jumbledWord);

        while (attempts > 0) {
            printf("\n\t\tJumbled Word: %s", jumbledWord);
            char guess[MAX_WORD_LENGTH + 1];

            printf("\n\t\tYour Guess: ");
            scanf("%s", guess);

            if (strcmp(guess, originalWord) == 0) {
                printf("\n\t\tCongratulations! You guessed the word correctly: %s\n", originalWord);
                sleep(1);
                score++;
                system("cls");
                break;
            } else {
                printf("\n\n\n\n\t\tIncorrect guess. Try again! Attempts left: %d\n", attempts - 1);
                attempts--;
            }
        }
    }

    printf("\n\n\n\n\n\n\t\tGame Over!\n");
    sleep(1);
    printf("\n\n\n\n\n\n\t\tYour final score is: %d/%lu\n", score, sizeof(words) / sizeof(words[0]));
    system("cls");
}