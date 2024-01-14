#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


// Maze Game
char maze[16][16] = {
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},//0
        {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},//1
        {'#', '.', '#', '#', '#', '.', '#', '#', '#', '#', '#', '#', '.', '#', '.', '#'},//2
        {'#', '.', '#', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '#', '.', '#'},//3
        {'#', '.', '#', '.', '#', '#', '#', '#', '#', '#', '#', '#', '.', '#', '.', '#'},//4
        {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},//5
        {'.', '.', '#', '.', '#', '.', '#', '#', '#', '.', '#', '#', '#', '#', '.', '#'},//6
        {'#', '.', '#', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '#'},//7
        {'#', '.', '#', '.', '#', '#', '#', '#', '#', '#', '#', '#', '.', '#', '#', '#'},//8
        {'#', '.', '#', '.', '#', '.', '#', '.', '.', '.', '#', '.', '.', '#', '.', '#'},//9
        {'#', '.', '#', '.', '.', '.', '#', '.', '#', '.', '.', '#', '.', '#', '.', '#'},//10
        {'#', '.', '#', '.', '#', '.', '#', '.', '#', '#', '.', '#', '.', '#', '.', '#'},//11
        {'#', '.', '#', '.', '#', '.', '.', '.', '#', '.', '.', '.', '.', '#', '.', '#'},//12
        {'#', '.', '#', '.', '#', '#', '#', '#', '#', '#', '#', '.', '#', '#', '.', '#'},//13
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '#'},//14
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '@', '#', '#'}//15
    // ... (haiqa's maze layout)
};

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void print_maze2() {
    int i, j;
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }

    gotoxy(50, 10);
    printf("PRESS 'i' TO READ INSTRUCTIONS");
    gotoxy(50, 12);
    printf("PRESS 'm' TO EXIT");
}

void instructions() {
    printf("\n\n\t\t\tINSTRUCTIONS : \n\n\n\t\t\tHELP THE SNAIL TO GET ACROSS THE MAZE");
    printf("\n\t\tUSE 'w' 'a' 's' 'd' TO MOVE\n\t\t\tPRESS 'm' TO EXIT\n\t\t\tGOOD LUCK..!!");
    getch();
    system("cls");
}

void playMazeGame() {
    char a, b;
    int x, y;
    x = 1;
    y = 6;
    
    printf("\n\n\n\n\n\n\n\n\t\t ________________________________________");
    printf("\n\t\t|*******WELCOME TO THE MAZE GAME*******|");
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
    printf("\n\n\n\n\n\n\t\t\t*******LET'S GO*******");
    sleep(1);
    system("cls");
    b = 'i';

    while (b != 'm') {
        if (x == 1 && y == 6) {
            system("cls");
            print_maze2();
            gotoxy(x * 2, y);
            printf("0");
			 
			char loop;
            loop = 'i';

            while (b != 'm') {
                system("cls");
                print_maze2();
                gotoxy(x * 2, y);
                printf("0");	
           

                if (kbhit()) {  
                    a = getch();  

                    int newX = x, newY = y;
                    switch (a) {
                        case 'a':
						newX--; 
						break;
                        case 'd':
						newX++;
						break;
                        case 's':
						newY++;
						break;
                        case 'w': 
						newY--;
						break;
                        case 'i':
                            system("cls");
                            instructions();
                            continue; 
                        case 'm':
                            b = 'm';
                            break;
                    }

                    if (maze[newY][newX] != '#') {
                        x = newX;
                        y = newY;
                    }

                    if (x ==13  && y ==15 ) {
                        system("cls");
                        printf("\n\n\n\n\n\n\t\t\t^^^^WHOOOOOOOOOO^^^^\n\t\t\tCONGRATULATIONS.. YOU WIN!!");
                        sleep(1);
                        printf("\n\n\t\t\t  PRESS 'm' TO QUIT THE GAME: ");
                        scanf(" %c", &b);
                        system("cls");
                        if (b !='m') {
                            system("cls");
                            printf("\n\n\n\t\t\t\t WE HOPE TO SEE YOU AGAIN....!!");
                            getch();
                        }
                        break;  
                    }
                }
            }
        }
    }
}