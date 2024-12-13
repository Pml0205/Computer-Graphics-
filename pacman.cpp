#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>

void grid();
void map();
void displayIntro();
void displayRules();
void gameOver();
int moveRight(int &x, int &y, int &boundary);
int moveLeft(int &x, int &y, int &boundary);
int moveUp(int &x, int &y, int &boundary);
int moveDown(int &x, int &y, int &boundary);

int main() {
    initwindow(640, 480, "Pacman Game");

    displayIntro();
    displayRules();

    grid();

    int pacX = 320, pacY = 240; // Pacman's starting position
    int boundaryX = 640, boundaryY = 480;
    char key = 'w';
    int boundary = 0; 
    while (true) {
        if (key == 'w') {
            moveUp(pacX, pacY, boundary);
        } else if (key == 'a') {
            moveLeft(pacX, pacY, boundary);
        } else if (key == 's') {
            moveDown(pacX, pacY, boundaryY);
        } else if (key == 'd') {
            moveRight(pacX, pacY, boundaryX);
        } else {
            gameOver();
            exit(0);
        }

        if (kbhit()) {
            key = getch();
        }
    }

    getch();
    closegraph();
    return 0;
}

void displayIntro() {
    setcolor(8);
    settextstyle(3, 0, 6);
    outtextxy(200, 200, "Pacman");
    delay(1000);
    setcolor(1);
    outtextxy(200, 200, "Pacman");
    delay(1000);
    setcolor(2);
    outtextxy(200, 200, "Pacman");
    delay(1000);
    setcolor(0);
    outtextxy(200, 200, "Pacman");
}

void displayRules() {
    settextstyle(3, 0, 1);
    setcolor(1);
    outtextxy(100, 100, "Rules");
    outtextxy(100, 120, "1. Press W for UP!");
    outtextxy(100, 140, "2. Press A for LEFT!");
    outtextxy(100, 160, "3. Press S for DOWN!");
    outtextxy(100, 180, "4. Press D for RIGHT!");
    outtextxy(100, 200, "5. Avoid crashing into walls!");
    outtextxy(100, 220, "6. Pressing any other key ends the game.");
    delay(5000);
    cleardevice();
}

void gameOver() {
    settextstyle(3, 0, 6);
    for (int color = 15; color > 0; color--) {
        setcolor(color);
        outtextxy(150, 200, "GAME OVER");
        delay(1000);
    }
}

void grid() {
    map();
    rectangle(0, 0, 640, 480); // Boundary for the grid
}

void map() {
    setcolor(2);
    rectangle(80, 80, 120, 120); // Example map block
    rectangle(240, 40, 280, 120);
    rectangle(360, 80, 440, 120);
    rectangle(480, 40, 560, 120);
    rectangle(40, 200, 120, 240);
    rectangle(200, 200, 280, 240);
    rectangle(360, 200, 440, 240);
    rectangle(520, 200, 600, 240);
}

int moveRight(int &x, int &y, int &boundary) {
    if (x + 20 < boundary) {
        setcolor(0);
        circle(x, y, 18);
        x += 10;
        setcolor(14);
        circle(x, y, 18);
        delay(50);
    } else {
        gameOver();
        exit(0);
    }
    return 0;
}

int moveLeft(int &x, int &y, int &boundary) {
    if (x - 20 > boundary) {
        setcolor(0);
        circle(x, y, 18);
        x -= 10;
        setcolor(14);
        circle(x, y, 18);
        delay(50);
    } else {
        gameOver();
        exit(0);
    }
    return 0;
}

int moveUp(int &x, int &y, int &boundary) {
    if (y - 20 > boundary) {
        setcolor(0);
        circle(x, y, 18);
        y -= 10;
        setcolor(14);
        circle(x, y, 18);
        delay(50);
    } else {
        gameOver();
        exit(0);
    }
    return 0;
}

int moveDown(int &x, int &y, int &boundary) {
    if (y + 20 < boundary) {
        setcolor(0);
        circle(x, y, 18);
        y += 10;
        setcolor(14);
        circle(x, y, 18);
        delay(50);
    } else {
        gameOver();
        exit(0);
    }
    return 0;
}
