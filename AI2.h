#pragma once
#include "Data.h"
#include "Model.h"
#include <iostream>
_POINT timkiemnuocdi2(_POINT _A[][BOARD_SIZE], bool _TURN);
double phongngucheonguoc2(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol);
double phongngucheoxuoi2(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol);
double phongngungang2(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol);
double phongngudoc2(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol);
double tancongcheonguoc2(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol);
double tancongcheoxuoi2(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol);
double tancongngang2(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol);
double tancongdoc2(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol); 
