#pragma once
#include <stdlib.h>
#include <Windows.h>
#include <glut.h>
#include <time.h>
#include <iostream>
using namespace std;

void initGrid(float x, float y);
void drawGrid();
void drawSnake();
void drawFood();
void checkPosFood();