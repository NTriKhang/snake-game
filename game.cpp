#include "game.h"

extern int snakeMove;
extern bool gameOver;
float gridX, gridY;
float foodX, foodY;
bool food = true;
float posX[40] = { 20,20,20,20,20 }, posY[40] = { 20,19,18,17,16 };
int length = 5;
void initGrid(float x, float y) {
	gridX = x;
	gridY = y;
}
void drawGrid() {
	glLineWidth(1);
	glColor3f(1.0, 1.0, 1.0);
	for (float i = 0; i < gridX; i++) {
		glBegin(GL_LINES);
		glVertex2f(i, 0);
		glVertex2f(i, gridY);
		glVertex2f(0, i);
		glVertex2f(gridX, i);
		glEnd();
	}
	
}
void drawSnake() {
	if (snakeMove != 0) {
		for (int i = length - 1; i > 0; i--) {
			posX[i] = posX[i - 1];
			posY[i] = posY[i - 1];
		}
	}

	if (snakeMove == 1) posX[0]++;
	else if (snakeMove == -1) posX[0]--;
	else if (snakeMove == 2) posY[0]++;
	else if (snakeMove == -2) posY[0]--;

	glColor3f(1.0, 0.0, 0.0);
	
	for (int i = 0; i < length; i++) {
		if (i == 0) glColor3f(0,1.0, 1.0);
		else glColor3f(1.0, 0, 0);
		glRectd(posX[i], posY[i], posX[i] + 1, posY[i] + 1);
	}	
	for (int i = 1; i < length; i++) {
		if (posX[0] == posX[i] && posY[0] == posY[i]) {
			gameOver = true;
			break;
		}
	}
	if (posX[0] == 0 || posX[0] == gridX || posY[0] == -1 || posY[0] == gridY) {
		gameOver = true;
	}
}
void drawFood() {

	srand(time(NULL));

	checkPosFood();

	if (food) {
		foodX = rand() % (int)gridX;
		foodY = rand() % (int)gridY;
		food = false;
	}
	glColor3f(0, 1.0, 0);
	glRectd(foodX, foodY, foodX + 1, foodY + 1);
}
void checkPosFood() {

	for (int i = 0; i < length; i++) {
		if (foodX == posX[i] && foodY == posY[i]) {
			food = true;
			length++;
		}
	}
}