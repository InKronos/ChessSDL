#include "stdafx.h"

//-------------------------------------
//Pobieranie tekstur
void getFigureTextures(SDL_Texture* arrayOfTextures[12], SDL_Renderer* renderer) { 
	arrayOfTextures[0] = LoadTexture("grafic/pawn0.png", renderer);
	arrayOfTextures[1] = LoadTexture("grafic/pawn1.png", renderer);
	arrayOfTextures[2] = LoadTexture("grafic/rook0.png", renderer);
	arrayOfTextures[3] = LoadTexture("grafic/rook1.png", renderer);
	arrayOfTextures[4] = LoadTexture("grafic/knight0.png", renderer);
	arrayOfTextures[5] = LoadTexture("grafic/knight1.png", renderer);
	arrayOfTextures[6] = LoadTexture("grafic/bishop0.png", renderer);
	arrayOfTextures[7] = LoadTexture("grafic/bishop1.png", renderer);
	arrayOfTextures[8] = LoadTexture("grafic/queen0.png", renderer);
	arrayOfTextures[9] = LoadTexture("grafic/queen1.png", renderer);
	arrayOfTextures[10] = LoadTexture("grafic/king0.png", renderer);
	arrayOfTextures[11] = LoadTexture("grafic/king1.png", renderer);
}

void getSignTextures(SDL_Texture* arrayOfTextures[9], SDL_Renderer* renderer) {
	arrayOfTextures[0] = LoadTexture("grafic/whiteSign.png", renderer);
	arrayOfTextures[1] = LoadTexture("grafic/blackSign.png", renderer);
	arrayOfTextures[2] = LoadTexture("grafic/whiteTurn.png", renderer);
	arrayOfTextures[3] = LoadTexture("grafic/blackTurn.png", renderer);
	arrayOfTextures[4] = LoadTexture("grafic/whiteEnd.png", renderer);
	arrayOfTextures[5] = LoadTexture("grafic/blackEnd.png", renderer);
	arrayOfTextures[6] = LoadTexture("grafic/anywhere.png", renderer);
	arrayOfTextures[7] = LoadTexture("grafic/updatePawn.png", renderer);
	arrayOfTextures[8] = LoadTexture("grafic/restart.png", renderer);
}
//-------------------------------------

SDL_Texture* LoadTexture(char* file, SDL_Renderer* renderer) { 
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(file);

	if (loadedSurface == NULL)
		printf("Unable to load an image from %s, SDL Error: %s \n", file, SDL_GetError());
	else {
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

		if (newTexture == NULL)
			printf("Unable to load an texture from %s, SDL Error: %s \n", file, SDL_GetError());
	}

	return newTexture;

}

void destroyTextures(SDL_Texture* arrayOfTextures[], int size) {
	for (int i = 0; i < size; i++)
		SDL_DestroyTexture(arrayOfTextures[i]);
}


void RenderBoard(SDL_Renderer* renderer, int board[8][8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j] == 0) {
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 200);
			}
			else if (board[i][j] == 1) {
				SDL_SetRenderDrawColor(renderer, 100, 100, 100, 200);
			}
			else if (board[i][j] == 2) {
				SDL_SetRenderDrawColor(renderer, 67, 211, 240, 230);
			}
			else if (board[i][j] == 3) {
				SDL_SetRenderDrawColor(renderer, 255, 0, 174, 215);
			}
			SDL_Rect squere = { 100 + (j * 100), (i * 100), 100, 100 };
			SDL_RenderFillRect(renderer, &squere);

		}
	}
}

void RenderFigures(SDL_Renderer* renderer, Figure board[8][8], SDL_Texture* arrayOfTextures[12]) {

	SDL_Texture* texture = NULL;
	Uint8 a = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j].type != 0) {
				if (board[i][j].player == 0) {
					if (board[i][j].type == Pawn)
						texture = arrayOfTextures[0];
					else if (board[i][j].type == Rook)
						texture = arrayOfTextures[2];
					else if (board[i][j].type == Knight)
						texture = arrayOfTextures[4];
					else if (board[i][j].type == Bishop)
						texture = arrayOfTextures[6];
					else if (board[i][j].type == Queen)
						texture = arrayOfTextures[8];
					else if (board[i][j].type == King)
						texture = arrayOfTextures[10];
				}
				if (board[i][j].player == 1) {
					if (board[i][j].type == Pawn)
						texture = arrayOfTextures[1];
					else if (board[i][j].type == Rook)
						texture = arrayOfTextures[3];
					else if (board[i][j].type == Knight)
						texture = arrayOfTextures[5];
					else if (board[i][j].type == Bishop)
						texture = arrayOfTextures[7];
					else if (board[i][j].type == Queen)
						texture = arrayOfTextures[9];
					else if (board[i][j].type == King)
						texture = arrayOfTextures[11];
				}
				SDL_Rect figure = { board[i][j].position_x, board[i][j].position_y, 100, 100 };
				SDL_RenderCopy(renderer, texture, NULL, &figure);
			}
		}
	}
}

void RenderSigns(SDL_Renderer* renderer, SDL_Texture* arrayOfTextures[9], Game * game)
{
	SDL_Texture* texture = NULL;
	int number;
	if (game->player) {
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 215);
		number = 0;
	}
		
	else {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 100);
		number = 1;
	}
	SDL_Rect rect = { 0, 0, 1000, 800 };
	SDL_RenderFillRect(renderer, &rect);
		
	texture = arrayOfTextures[number];
	SDL_Rect sign1 = { 0, 0, 100, 800 };
	SDL_RenderCopy(renderer, texture, NULL, &sign1);
	texture = arrayOfTextures[number+2];
	SDL_Rect sign2 = { 900, 0, 100, 800 };
	SDL_RenderCopy(renderer, texture, NULL, &sign2);

}

void RenderEndOfTheGame(SDL_Renderer* renderer, SDL_Texture* arrayOfTextures[9], Game* game)
{
	SDL_SetRenderDrawColor(renderer, 125, 125, 125, 100);
	SDL_Rect rect = { 250, 200, 500, 400 };
	SDL_RenderFillRect(renderer, &rect);
	SDL_Rect rect1 = { 250, 200, 500, 50 };
	SDL_RenderCopy(renderer, arrayOfTextures[8], NULL, &rect1);
	if(game->player)
		SDL_RenderCopy(renderer, arrayOfTextures[4], NULL, &rect);
	else
		SDL_RenderCopy(renderer, arrayOfTextures[5], NULL, &rect);
	SDL_Rect rect2 = { 250, 550, 500, 50 };
	SDL_RenderCopy(renderer, arrayOfTextures[6], NULL, &rect2);
}


void RenderUpdatePawn(SDL_Renderer* renderer, SDL_Texture* arrayOfTextures[9])
{

	SDL_SetRenderDrawColor(renderer, 125, 125, 125, 100);
	SDL_Rect rect = { 250, 200, 500, 400 };
	SDL_RenderFillRect(renderer, &rect);
	SDL_RenderCopy(renderer, arrayOfTextures[7], NULL, &rect);
}