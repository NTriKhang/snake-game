#include <iostream>
using namespace std;
#include <Windows.h>
#include <stdlib.h>
#include <glut.h>
#include "game.h"
#include <ImageHlp.h>

const float FPS = 10;
const float COLUMN = 40;
const float ROW = 40;
int snakeMove = 0;
bool gameOver = false;

void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);

	initGrid(COLUMN, ROW);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, COLUMN, 0, ROW, -1, 1);
}
void display_callback();
void special_callback(int key, int, int);
void timer_callback(int x);
int main(int argv, char** argc) {
	glutInit(&argv, argc);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Snake game");
	init();
	glutDisplayFunc(display_callback);
	glutSpecialFunc(special_callback);
	glutTimerFunc(0, timer_callback, 0);

	glutMainLoop();
}
void timer_callback(int x) {
	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, timer_callback, 0);
}
void special_callback(int key, int x, int y) {
	
	switch (key)
	{
	case GLUT_KEY_RIGHT:
		if (snakeMove == -1) break;
		snakeMove = 1;
		break;
	case GLUT_KEY_LEFT:	
		if (snakeMove == 1) break;
		snakeMove = -1;
		break;
	case GLUT_KEY_UP:
		if (snakeMove == -2) break;
		snakeMove = 2;
		break;
	case GLUT_KEY_DOWN:
		if (snakeMove == 2) break;
		snakeMove = -2;
		break;
	default:
		break;
	}
}
void display_callback() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	if (gameOver) {
		MessageBox(0, (LPCWSTR)"YOUR SCORE: ", (LPCWSTR)"GAME OVER", 0);
		exit(0);
	}

	//drawGrid();
	drawSnake();
	drawFood();
	
	glutSwapBuffers();
}