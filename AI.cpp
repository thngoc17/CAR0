#include "AI.h" 
double mangdiemtancong[7] = { 0,1,9,81,729,6561,59049 };
//double mangdiemtancong[7] = { 0,8,100,1535,12287,15552 ,93312};
double mangdiemphongngu[7] = { 0, 3, 24, 192, 1536, 12288, 98034 };
//double mangdiemphongngu[7] = { 0, 1, 8, 64, 512, 4096, 32768 };
double tancongdoc(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol) {
	int soquanta = 0;
	int soquandich = 0;
	double diemtong = 0;
	int flag = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (GetRowIndex(_A[i][j].y) == currentRow && GetColIndex(_A[i][j].x) == currentCol)
			{
				// an doc
				for (int t = 1; t < 7 && i - t >= 0; t++) {
					if (_A[i - t][j].c == -1) {
						soquanta++;
						if (soquanta < 4 && i - t - 1 == 0) {
							soquanta = 0;
							break;
						}
					}

					else if (_A[i - t][j].c == 1)
					{
						soquandich++;
						break;
					}
					else
					{
						break;
					}
				}
				for (int t = 1; t < 7 && i + t < BOARD_SIZE; t++) {
					if (_A[i + t][j].c == -1) {
						soquanta++;
						if (soquanta < 4 && i + t + 1 == BOARD_SIZE - 1) {
							soquanta = 0;
							break;
						}
					}

					else if (_A[i + t][j].c == 1)
					{
						soquandich++;
						break;
					}
					else
					{
						break;
					}
				}
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
	}
	if (soquandich == 2)
		return 0;
	diemtong -= mangdiemphongngu[soquandich + 1];
	diemtong += mangdiemtancong[soquanta];
	return diemtong;
}

double tancongngang(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol) {
	int soquanta = 0;
	int soquandich = 0;
	double diemtong = 0;
	int flag = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (GetRowIndex(_A[i][j].y) == currentRow && GetColIndex(_A[i][j].x) == currentCol)
			{
				// an doc
				for (int t = 1; t < 7 && j - t >= 0; t++) {
					if (_A[i][j - t].c == -1) {
						soquanta++;
						if (soquanta < 4 && j - t - 1 == 0) {
							soquanta = 0;
							break;
						}
					}

					else if (_A[i][j - t].c == 1)
					{
						soquandich++;
						break;
					}
					else
					{
						break;
					}
				}
				for (int t = 1; t < 7 && j + t < BOARD_SIZE; t++) {
					if (_A[i][j + t].c == -1) {
						soquanta++;
						if (soquanta < 4 && j + t + 1 == BOARD_SIZE - 1) {
							soquanta = 0;
							break;
						}
					}

					else if (_A[i][j + t].c == 1)
					{
						soquandich++;
						break;
					}
					else
						break;
				}
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
	}
	if (soquandich == 2)
		return 0;
	diemtong -= mangdiemphongngu[soquandich + 1];
	diemtong += mangdiemtancong[soquanta];
	return diemtong;
}

double tancongcheoxuoi(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol) {
	int soquanta = 0;
	int soquandich = 0;
	double diemtong = 0;
	int flag = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (GetRowIndex(_A[i][j].y) == currentRow && GetColIndex(_A[i][j].x) == currentCol)
			{
				for (int t = 1; t < 7 && j - t >= 0 && i - t >= 0; t++) {
					if (_A[i - t][j - t].c == -1) {
						soquanta++;
						if (soquanta < 4 && (i - t - 1 == 0 || j - t - 1 == 0)) {
							soquanta = 0;
							break;
						}
					}

					else if (_A[i - t][j - t].c == 1)
					{
						soquandich++;
						break;
					}
					else
						break;
				}
				for (int t = 1; t < 7 && i + t < BOARD_SIZE && j + t < BOARD_SIZE; t++) {
					if (_A[i + t][j + t].c == -1) {
						soquanta++;
						if (soquanta < 4 && (i + t + 1 == BOARD_SIZE - 1 || j + t + 1 == BOARD_SIZE - 1)) {
							soquanta = 0;
							break;
						}
					}

					else if (_A[i + t][j + t].c == 1)
					{
						soquandich++;
						break;
					}
					else
						break;
				}
				flag = 1;
				break;
			}

		}
		if (flag == 1) break;
	}
	if (soquandich == 2)
		return 0;
	diemtong -= mangdiemphongngu[soquandich + 1];
	diemtong += mangdiemtancong[soquanta];
	return diemtong;
}

double tancongcheonguoc(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol) {
	int soquanta = 0;
	int soquandich = 0;
	double diemtong = 0;
	int flag = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (GetRowIndex(_A[i][j].y) == currentRow && GetColIndex(_A[i][j].x) == currentCol)
			{
				for (int t = 1; t < 7 && j + t < BOARD_SIZE && i - t >= 0; t++) {
					if (_A[i - t][j + t].c == -1) {
						soquanta++;
						if (soquanta < 4 && (i - t - 1 == 0 || j + t + 1 == BOARD_SIZE - 1)) {
							soquanta = 0;
							break;
						}
					}

					else if (_A[i - t][j + t].c == 1)
					{
						soquandich++;
						break;
					}
					else
						break;
				}
				for (int t = 1; t < 7 && i + t < BOARD_SIZE && j - t >= 0; t++) {
					if (_A[i + t][j - t].c == -1) {
						soquanta++;
						if (soquanta < 4 && (i + t + 1 == BOARD_SIZE - 1 || j - t - 1 == 0)) {
							soquanta = 0;
							break;
						}
					}

					else if (_A[i + t][j - t].c == 1)
					{
						soquandich++;
						break;
					}
					else
						break;
				}
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;

	}
	if (soquandich == 2)
		return 0;
	diemtong -= mangdiemphongngu[soquandich + 1];
	diemtong += mangdiemtancong[soquanta];
	return diemtong;
}

double phongngudoc(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol) {
	int soquanta = 0;
	int soquandich = 0;
	double diemtong = 0;
	int flag = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (GetRowIndex(_A[i][j].y) == currentRow && GetColIndex(_A[i][j].x) == currentCol)
			{
				// an doc
				for (int t = 1; t < 7 && i - t >= 0; t++) {
					if (_A[i - t][j].c == -1) {
						soquanta++;
						break;
					}
					else if (_A[i - t][j].c == 1)
					{
						soquandich++;
						if (soquandich < 4 && i - t - 1 == 0) {
							soquandich = 0;
							break;
						}
					}
					else
						break;
				}
				for (int t = 1; t < 7 && i + t < BOARD_SIZE; t++) {
					if (_A[i + t][j].c == -1) {
						soquanta++;
						break;
					}
					else if (_A[i + t][j].c == 1)
					{
						soquandich++;
						if (soquandich < 4 && i + t + 1 == BOARD_SIZE - 1) {
							soquandich = 0;
							break;
						}
					}
					else
						break;
				}
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;

	}
	if (soquanta == 2)
		return 0;
	diemtong -= mangdiemtancong[soquanta];
	diemtong += mangdiemphongngu[soquandich];
	return diemtong;
}

double phongngungang(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol) {
	int soquanta = 0;
	int soquandich = 0;
	double diemtong = 0;
	int flag = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (GetRowIndex(_A[i][j].y) == currentRow && GetColIndex(_A[i][j].x) == currentCol)
			{
				// an doc
				for (int t = 1; t < 7 && j - t >= 0; t++) {
					if (_A[i][j - t].c == -1) {
						soquanta++;
						break;
					}
					else if (_A[i][j - t].c == 1)
					{
						soquandich++;
						if (soquandich < 4 && j - t - 1 == 0) {
							soquandich = 0;
							break;
						}
					}
					else
						break;
				}
				for (int t = 1; t < 7 && j + t < BOARD_SIZE; t++) {
					if (_A[i][j + t].c == -1) {
						soquanta++;
						break;
					}
					else if (_A[i][j + t].c == 1)
					{
						soquandich++;
						if (soquandich < 4 && j + t + 1 == BOARD_SIZE - 1) {
							soquandich = 0;
							break;
						}
					}
					else
						break;
				}
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;

	}
	if (soquanta == 2)
		return 0;
	diemtong -= mangdiemtancong[soquanta];
	diemtong += mangdiemphongngu[soquandich];
	return diemtong;
}

double phongngucheoxuoi(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol) {
	int soquanta = 0;
	int soquandich = 0;
	double diemtong = 0;
	int flag = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (GetRowIndex(_A[i][j].y) == currentRow && GetColIndex(_A[i][j].x) == currentCol)
			{
				for (int t = 1; t < 7 && j - t >= 0 && i - t >= 0; t++) {
					if (_A[i - t][j - t].c == -1) {
						soquanta++;
						break;
					}
					else if (_A[i - t][j - t].c == 1)
					{
						soquandich++;
						if (soquandich < 4 && (i - t - 1 == 0 || j - t - 1 == 0)) {
							soquandich = 0;
							break;
						}
					}
					else
						break;
				}
				for (int t = 1; t < 7 && i + t < BOARD_SIZE && j + t < BOARD_SIZE; t++) {
					if (_A[i + t][j + t].c == -1) {
						soquanta++;
						break;
					}
					else if (_A[i + t][j + t].c == 1)
					{
						soquandich++;
						if (soquandich < 4 && (i + t + 1 == BOARD_SIZE - 1 || j + t + 1 == BOARD_SIZE - 1)) {
							soquandich = 0;
							break;
						}
					}
					else
						break;
				}
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;

	}
	if (soquanta == 2)
		return 0;
	diemtong -= mangdiemtancong[soquanta];
	diemtong += mangdiemphongngu[soquandich];
	return diemtong;
}

double phongngucheonguoc(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol) {
	int soquanta = 0;
	int soquandich = 0;
	double diemtong = 0;
	int flag = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (GetRowIndex(_A[i][j].y) == currentRow && GetColIndex(_A[i][j].x) == currentCol)
			{
				for (int t = 1; t < 7 && j + t < BOARD_SIZE && i - t >= 0; t++) {
					if (_A[i - t][j + t].c == -1) {
						soquanta++;
						break;
					}
					else if (_A[i - t][j + t].c == 1)
					{
						soquandich++;
						if (soquandich < 4 && (i - t - 1 == 0 || j + t + 1 == BOARD_SIZE - 1)) {
							soquandich = 0;
							break;
						}
					}
					else
						break;
				}
				for (int t = 1; t < 7 && i + t < BOARD_SIZE && j - t >= 0; t++) {
					if (_A[i + t][j - t].c == -1) {
						soquanta++;
						break;
					}
					else if (_A[i + t][j - t].c == 1)
					{
						soquandich++;
						if (soquandich < 4 && (i + t + 1 == BOARD_SIZE - 1 || j - t - 1 == 0)) {
							soquandich = 0;
							break;
						}
					}
					else
						break;
				}
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
	}
	if (soquanta == 2)
		return 0;
	diemtong -= mangdiemtancong[soquanta];
	diemtong += mangdiemphongngu[soquandich];
	return diemtong;
}
_POINT timkiemnuocdi(_POINT _A[][BOARD_SIZE], bool _TURN) {
	_POINT wayresult{};
	wayresult.x = -1;
	wayresult.y = -1;
	double diemMax = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (_A[i][j].c == 0) {
				double diemtancong = tancongdoc(_A, i, j) + tancongngang(_A, i, j) + tancongcheoxuoi(_A, i, j) + tancongcheonguoc(_A, i, j);
				double diemphongngu = phongngudoc(_A, i, j) + phongngungang(_A, i, j) + phongngucheoxuoi(_A, i, j) + phongngucheonguoc(_A, i, j);
				double temp = diemtancong > diemphongngu ? diemtancong : diemphongngu;
				if (diemMax < temp)
				{
					diemMax = temp;
					wayresult.x = _A[i][j].x;
					wayresult.y = _A[i][j].y;
					wayresult.c = (_TURN) ? -1 : 1;
				}
			}
		}
	}
	return wayresult;
}