#pragma once
#include <iostream>

struct Player {
    std::string name;
    int id;
    int password;
};

// Enemy functions
void genEnemy(int ind);
void drawEnemy(int ind);

// Bullet functions
void genbullet();
void movebullet();
void drawbullets();

// Shooter functions
void drawshooter();
int collision();
