#include "stdafx.h"

void CreateBoard(Figure board[8][8]) {
	//tworzenie ponków
	for (int i = 0; i < 8; i++) {
		Figure pawn1 = { i * 100 + 100, 600, Pawn, 1, 0 };
		board[6][i] = pawn1;
		Figure pawn0 = { i * 100 + 100, 100, Pawn, 0, 0 };
		board[1][i] = pawn0;
	}
	//tworzenie figur od wie¿y do goñca
	int position = 700;
	int diffrence = 0;
	int type = Rook;
	for (int i = 0; i < 6; i++) {
		if (i % 2 == 0) {
			Figure figure0 = { diffrence + 100, 0, type, 0, 0 };
			board[0][(diffrence / 100)] = figure0;
			Figure figure1 = { diffrence + 100, 700, type, 1, 0 };
			board[7][(diffrence / 100)] = figure1;
		}
		else {
			Figure figure0 = { position - diffrence + 100, 0, type, 0, 0 };
			board[0][(position / 100) - (diffrence / 100)] = figure0;
			Figure figure1 = { position - diffrence + 100, 700, type, 1, 0 };
			board[7][(position/100) - (diffrence / 100)] = figure1;
			diffrence += 100;
			type++;
		}
	}
	//tworzenie króla i hetmana
	Figure king0 = { 500, 0, King, 0, 0 };
	board[0][4] = king0;
	Figure king1 = { 500, 700, King, 1, 0 };
	board[7][4] = king1;
	Figure queen0 = { 400, 0, Queen, 0, 0 };
	board[0][3] = queen0;
	Figure queen1 = { 400, 700, Queen, 1, 0 };
	board[7][3] = queen1;
	//wype³ninie tablicy "pustymi" figurami
	for (int i = 2; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			Figure blank = { 0, 0, 0, 0, 0 };
			board[i][j] = blank;
		}
	}
}

void MakeFiguresUnready(Figure board[8][8])
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			board[i][j].readyToMove = false;
	}
}

void FillBoard(int board[8][8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2 == 1)
				board[i][j] = 1;
			else
				board[i][j] = 0;
		}
	}
}


void GetPos(int* x, int* y)
{
	double floatx = ((*x) - 100) / 100;
	double floaty = (*y) / 100;
	int newX = (int)floor(floatx);
	int newY = (int)floor(floaty);
	*x = newY; //oœ Y jest pierwszym wymiarem w tablicy dwuwymiarowej
	*y = newX; //oœ X jest drugim wymiarem w tablicy dwuwymiarowej
}

void colorBoard(int x, int y, int newX, int newY, Figure board[8][8], int boardLook[8][8], bool* toProcess) {
	if (board[newX][newY].type == 0) { //jeœli nie ma ¿adnego przeciwnika
		boardLook[newX][newY] = 2;
		board[x][y].readyToMove = true;
	}
	else if (board[newX][newY].player != board[x][y].player) { //jeœli jest jakiœ przeciwnik
		boardLook[newX][newY] = 3;
		*toProcess = false;
		board[x][y].readyToMove = true;
	}
}