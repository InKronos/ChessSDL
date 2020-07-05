#include "stdafx.h"




void FindPos(int x, int y, Figure board[8][8], int boardLook[8][8], Game* game) {
	if (board[x][y].type != 0) {
		if (board[x][y].player == game->player) {
			if (board[x][y].type == Pawn) { //ruch pionka
				MovOfPawn(x, y, board, boardLook);
			}
			if (board[x][y].type == Knight) { //ruch konia
				MovOfKnight(x, y, board, boardLook);
			}
			if (board[x][y].type == Rook) { //ruch wie�y
				MovOfRook(x, y, board, boardLook);
			}
			if (board[x][y].type == Bishop) { //ruch go�ca
				MovOfBishop(x, y, board, boardLook);
			}
			if (board[x][y].type == Queen) { //ruch hetmana - hetman posiada kombinacje ruch�w wie�y i go�ca dlatego nie op�aca si� robi� dodatkowej funkcji
				MovOfBishop(x, y, board, boardLook);
				MovOfRook(x, y, board, boardLook);
			}
			if (board[x][y].type == King) { //ruch kr�la
				MovOfKing(x, y, board, boardLook);
			}
			game->state = WaitingForMove;
		}
		
	}
}


void MovOfPawn(int x, int y, Figure board[8][8], int boardLook[8][8]) {
	bool getReady = false;
	if (board[x][y].player == 0) { //pionek czarny porusza si� w d�
		if (x == 1) {
			if (board[x + 2][y].type == None) {
				boardLook[x + 2][y] = 2;
				getReady = true;
			}
		}
		if (x+1 < 8 && board[x + 1][y].type == None) {
			boardLook[x + 1][y] = 2;
			getReady = true;
		}
		if (x+1 < 8 && y-1 >= 0 && board[x + 1][y - 1].type != None && board[x + 1][y - 1].player == 1) {
			boardLook[x + 1][y - 1] = 3;
			getReady = true;
		}
		if (x + 1 < 8 && y + 1 < 8 && board[x + 1][y + 1].type != None && board[x + 1][y + 1].player == 1) {
			boardLook[x + 1][y + 1] = 3;
			getReady = true;
		}
			
	}
	if (board[x][y].player == 1) { //pionek czarny porusza si� w g�re
		if (x == 6) {
			if (board[x - 2][y].type == None) {
				boardLook[x - 2][y] = 2;
				getReady = true;
			}
		}
		if (board[x - 1][y].type == None) {
			boardLook[x - 1][y] = 2;
			getReady = true;
		}
		if (x - 1 >= 0 && y - 1 >= 0 && board[x - 1][y - 1].type != None && board[x - 1][y - 1].player == 0) {
			boardLook[x - 1][y - 1] = 3;
			getReady = true;
		}
		if (x - 1 >= 0 && y + 1 < 8 && board[x - 1][y + 1].type != None && board[x - 1][y + 1].player == 0) {
			boardLook[x - 1][y + 1] = 3;
			getReady = true;
		}

			
	}
	if(getReady)
		board[x][y].readyToMove = true;
}

void MovOfKnight(int x, int y, Figure board[8][8], int boardLook[8][8])
{
	bool uselessBool = false; // zmienna nie potrzebna koniu ale potrzebna go�cowi i wie�y, a w j�zyku C nie da si� domy�lnych waro�ci
	int newX, newY;
	if (x + 1 < 8) {
		newX = x + 1;
		if (y + 2 < 8) {
			newY = y + 2;
			colorBoard(x, y, newX, newY, board, boardLook, &uselessBool);
		}
		if (y - 2 >= 0) {
			newY = y - 2;
			colorBoard(x, y, newX, newY, board, boardLook, &uselessBool);
		}
	}
	if (x - 1 >= 0) {
		newX = x - 1;
		if (y + 2 < 8) {
			newY = y + 2;
			colorBoard(x, y, newX, newY, board, boardLook, &uselessBool);
		}
		if (y - 2 >= 0) {
			newY = y - 2;
			colorBoard(x, y, newX, newY, board, boardLook, &uselessBool);
		}
	}
	if (y - 1 >= 0) {
		newY = y - 1;
		if (x + 2 < 8) {
			newX = x + 2;
			colorBoard(x, y, newX, newY, board, boardLook, &uselessBool);
		}
		if (x - 2 >= 0) {
			newX = x - 2;
			colorBoard(x, y, newX, newY, board, boardLook, &uselessBool);
		}
	}
	if (y + 1 < 8) {
		newY = y + 1;
		if (x + 2 < 8) {
			newX = x + 2;
			colorBoard(x, y, newX, newY, board, boardLook, &uselessBool);
		}
		if (x - 2 >= 0) {
			newX = x - 2; 
			colorBoard(x, y, newX, newY, board, boardLook, &uselessBool);
		}
	}
}

void MovOfRook(int x, int y, Figure board[8][8], int boardLook[8][8])
{
	bool howLong[4] = { 1, 1, 1, 1 }; // tablica zmiennych logicznych sprawdzaj�ca czy w danym kierunku mo�na jeszcze i��
	int newX, newY;
	for (int i = 1; i < 8; i++) {
		if (howLong[0]) {
			if (x + i < 8) {
				newX = x + i;
				if (board[newX][y].player == board[x][y].player && board[newX][y].type != None) // je�li natrafimy na swojego pionka nie da si� i�� dalej
					howLong[0] = false;
				else
					colorBoard(x, y, newX, y, board, boardLook, &howLong[0]);
	
			}
		}
		if (howLong[1]) {
			if (x - i >= 0) {
				newX = x - i;
				if (board[newX][y].player == board[x][y].player && board[newX][y].type != None)
					howLong[1] = false;
				else
					colorBoard(x, y, newX, y, board, boardLook, &howLong[1]);

			}
		}
		if (howLong[2]) {
			if (y + i < 8) {
				newY = y + i;
				if (board[x][newY].player == board[x][y].player && board[x][newY].type != None)
					howLong[2] = false;
				else
					colorBoard(x, y, x, newY, board, boardLook, &howLong[2]);

			}
		}
		if (howLong[3]) {
			if (y - i >= 0) {
				newY = y - i;
				if (board[x][newY].player == board[x][y].player && board[x][newY].type != None)
					howLong[3] = false;
				else
					colorBoard(x, y, x, newY, board, boardLook,&howLong[3]);
			}
		}
	}
}

void MovOfBishop(int x, int y, Figure board[8][8], int boardLook[8][8])
{
	bool howLong[4] = { 1, 1, 1, 1 }; // tablica zmiennych logicznych sprawdzaj�ca czy w danym kierunku mo�na jeszcze i��
	int newX, newY;
	for (int i = 1; i < 8; i++) {
		if (howLong[0]) {
			if (x + i < 8 && y + i < 8) {
				newX = x + i;
				newY = y + i;
				if (board[newX][newY].player == board[x][y].player && board[newX][newY].type != None) // je�li natrafimy na swojego pionka nie da si� i�� dalej
					howLong[0] = false;
				else
					colorBoard(x, y, newX, newY, board, boardLook, &howLong[0]);
			}
		}
		if (howLong[1]) {
			if (x - i >= 0 && y - i >= 0) {
				newX = x - i;
				newY = y - i;
				if (board[newX][newY].player == board[x][y].player && board[newX][newY].type != None)
					howLong[1] = false;
				else
					colorBoard(x, y, newX, newY, board, boardLook, &howLong[1]);
			}
		}
		if (howLong[2]) {
			if (x - i >= 0 && y + i < 8) {
				newX = x - i;
				newY = y + i;
				if (board[newX][newY].player == board[x][y].player && board[newX][newY].type != None)
					howLong[2] = false;
				else
					colorBoard(x, y, newX, newY, board, boardLook, &howLong[2]);
			}
		}
		if (howLong[3]) {
			if (x + i < 8 && y - i >= 0) {
				newX = x + i;
				newY = y - i;
				if (board[newX][newY].player == board[x][y].player && board[newX][newY].type != None)
					howLong[3] = false;
				else
					colorBoard(x, y, newX, newY, board, boardLook, &howLong[3]);
			}
		}
	}
}

void MovOfKing(int x, int y, Figure board[8][8], int boardLook[8][8])
{	
	bool uselessBool = true;  // zmienna nie potrzebna kr�lowi ale potrzebna go�cowi i wie�y, a w j�zyku C nie da si� domy�lnych waro�ci
	int newX, newY;
	if (x + 1 < 8) {
		newX = x + 1;
		colorBoard(x, y, newX, y, board, boardLook, &uselessBool);
		if (y + 1 < 8) {
			newY = y + 1;
			colorBoard(x, y, newX, newY, board, boardLook, &uselessBool);
			colorBoard(x, y, x, newY, board, boardLook, &uselessBool);
		}
		if (y - 1 >= 0) {
			newY = y - 1;
			colorBoard(x, y, newX, newY, board, boardLook, &uselessBool);
			colorBoard(x, y, x, newY, board, boardLook, &uselessBool);
		}
	}
	if (x - 1 >= 0) {
		newX = x - 1;
		colorBoard(x, y, newX, y, board, boardLook, &uselessBool);
		if (y + 1 < 8) {
			newY = y + 1;
			colorBoard(x, y, newX, newY, board, boardLook, &uselessBool);
			colorBoard(x, y, x, newY, board, boardLook, &uselessBool);
		}
		if (y - 1 >= 0) {
			newY = y - 1;
			colorBoard(x, y, newX, newY, board, boardLook, &uselessBool);
			colorBoard(x, y, x, newY, board, boardLook, &uselessBool);
		}
	}
}



void ChangePos(int x, int y, Figure board[8][8], Game *game)
{
	bool end = false; //zmienna do przerwania drugiej p�tli
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j].readyToMove == true) {
				Figure blank = { 0, 0, 0, 0, 0 };
				if (board[x][y].type == King) //je�li weszli�my na kr�la
					game->state = EndOfTheGame;
				board[x][y] = board[i][j];
				board[i][j] = blank; //wype�nianie ostatniej pozycji "pust�" figur�
				board[x][y].readyToMove = false;
				board[x][y].position_x = y * 100 + 100;
				board[x][y].position_y = x * 100;
				if (board[x][y].type == Pawn) {
					if ((board[x][y].player == 1 && x == 0) || (board[x][y].player == 0 && x == 7)) { //je�li pionkiem osi�gneli�my koniec planszy
						if (game->state != EndOfTheGame) {
							game->state = UpdatePawnValue;
							board[x][y].readyToMove = true;
						}
					}
				}
				end = true;
				break;
			}
		}
		if (end)
			break;
	}
	if (game->player && game->state == WaitingForMove) //zamiana tury gracza je�li ruch nie spowodowa� ko�ca gry lub ulepszenia pionka
		game->player = false;
	else if (!game->player && game->state == WaitingForMove)
		game->player = true;
		
}


void UpdatePawn(int x, int y, Figure board[8][8], Game* game) {
	Type updateType = None;
	if (x > 250 && x < 750) { //wyszukanie pozycji napisu
		if (y > 275 && y < 350)
			updateType = Queen;
		else if (y > 350 && y < 415)
			updateType = Bishop;
		else if (y > 415 && y < 480)
			updateType = Knight;
		else if (y > 480 && y < 560)
			updateType = Rook;
		else
			return;
	}
	if (updateType != None) {
		bool end = false;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board[i][j].readyToMove == true) {
					board[i][j].type = updateType; //zmiana typu pionka na wybrany
					board[i][j].readyToMove = false;
					game->state = WaitingForAction;
					end = true;
					break;
				}
			}
			if (end)
				break;
		}
		if (game->player)
			game->player = false;
		else if (!game->player)
			game->player = true;
	}
}