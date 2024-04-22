#pragma once
#include "Data.h"
#include "Model.h"
#include <iostream>
_POINT timkiemnuocdi(_POINT _A[][BOARD_SIZE], bool _TURN);
double phongngucheonguoc(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol);
double phongngucheoxuoi(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol);
double phongngungang(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol);
double phongngudoc(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol);
double tancongcheonguoc(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol);
double tancongcheoxuoi(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol);
double tancongngang(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol);
double tancongdoc(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol);