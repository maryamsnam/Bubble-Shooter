#pragma once
#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

// Game variables
extern int enemyX[4], enemyY[4];
extern int enemyFlag[4];
extern int bullets[20][4];
extern int shooter[3][5];
extern int shooterposition;

// Game functions
void genEnemy(int ind);
void drawEnemy(int ind);
void genbullet();
void movebullet();
void drawbullets();
void drawshooter();
int collision();
void gameLoop();
