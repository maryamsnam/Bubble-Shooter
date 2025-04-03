#include "game.h"
#include <windows.h>

// Game variables
int enemyX[4], enemyY[4];
int enemyFlag[4];
int bullets[20][4];
int shooter[3][5] = {
    {0,1,1,1,0},
    {1,1,1,1,1},
    {0,1,1,1,0}
};
int shooterposition = 36;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void genEnemy(int ind) {
    enemyX[ind] = 3 + rand() % (70 - 10);
}

void drawEnemy(int ind) {
    if (enemyFlag[ind] == true) {
        gotoxy(enemyX[ind], enemyY[ind]); cout << " ** ";
        gotoxy(enemyX[ind], enemyY[ind]+1); cout << " ** ";
        gotoxy(enemyX[ind], enemyY[ind]+2); cout << " ** ";
        gotoxy(enemyX[ind], enemyY[ind]+3); cout << " ** ";
    }
}

void genbullet() {
    bullets[0][0] = 22;
    bullets[0][1] = shooterposition;
    bullets[0][2] = 22;
    bullets[0][3] = shooterposition+4;
}

void movebullet() {
    for(int i=0; i<20; i++) {
        if(bullets[i][0] > 2) bullets[i][0]--;
        else bullets[i][0] = 0;
        
        if(bullets[i][2] > 2) bullets[i][2]--;
        else bullets[i][2] = 0;
    }
}

void drawbullets() {
    for(int i=0; i<20; i++) {
        if(bullets[i][0] > 1) {
            gotoxy(bullets[i][1], bullets[i][0]); cout << " , ";
            gotoxy(bullets[i][3], bullets[i][2]); cout << " , ";
        }
    }
}

void drawshooter() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<5; j++) {
            gotoxy(j+shooterposition, i+22);
            cout << (char)shooter[i][j];
        }
    }
}

int collision() {
    if(enemyY[0]+4 >= 23) {
        if(enemyX[0]+4-shooterposition >= 0 && enemyX[0]+4-shooterposition < 8) {
            return 1;
        }
    }
    return 0;
}

void gameLoop() {
    system("cls");
    cout << "Press any key to start...";
    getch();
    
    for(int i=0; i<4; i++) {
        enemyY[i] = 1;
