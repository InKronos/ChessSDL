#include "stdafx.h"

void initialisation(int BoardLook[8][8], Figure BoardOfFigures[8][8], Game* game)
{
	FillBoard(BoardLook);
	CreateBoard(BoardOfFigures);
	game->state = WaitingForAction;
	game->player = 1; // zaczynamy od gracza bia³ego czyli 1
}

void render(SDL_Renderer* renderer, SDL_Texture* arrayOfSignTextures[9], SDL_Texture* arrayOfFigureTextures[12], int boardLook[8][8], Figure BoardOfFigures[8][8], Game* game)
{
	RenderSigns(renderer, arrayOfSignTextures, game);
	RenderBoard(renderer, boardLook);
	RenderFigures(renderer, BoardOfFigures, arrayOfFigureTextures);
	if (game->state == EndOfTheGame) {
		RenderEndOfTheGame(renderer, arrayOfSignTextures, game);
	}
	if (game->state == UpdatePawnValue) {
		RenderUpdatePawn(renderer, arrayOfSignTextures);
	}
}
