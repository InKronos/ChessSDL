#include "stdafx.h"

//---------------------------------------------
//Autorem tego projektu jest Pawe³ Piórkowski
//---------------------------------------------

int main()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf_s("error Plese start again");
		return 0;
	}
	printf_s("noice");
	
	// --------------------------------------------------------------
	//Czêœæ odpowiadaj¹ca za tworzenie gry
	SDL_Window* window = SDL_CreateWindow("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800, SDL_WINDOW_OPENGL);
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_Texture* arrayOfFigureTextures[12];
	SDL_Texture* arrayOfSignTextures[9];
	getFigureTextures(arrayOfFigureTextures, renderer);
	getSignTextures(arrayOfSignTextures, renderer);
	SDL_Event  event;
	Game* game = (Game*)malloc(sizeof(Game));
	Figure BoardOfFigures[8][8];
	int boardLook[8][8] = { 0 };
	
	initialisation(boardLook, BoardOfFigures, game);
	// --------------------------------------------------------------
	while (1) {
		// --------------------------------------------------------------
		//Czêœæ odpowiadaj¹ca za obsuge zdarzeñ
		if (SDL_PollEvent( & event)) {
			if (event.type == SDL_QUIT) {
				break;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				if (event.button.button == SDL_BUTTON_LEFT) {
					int x, y;
					
					SDL_GetMouseState(&x, &y);
					
					if (game->state == WaitingForAction) {
						GetPos(&x, &y);
						FindPos(x, y, BoardOfFigures, boardLook, game);
					}	
					else if (game->state == WaitingForMove) {
						GetPos(&x, &y);
						if (boardLook[x][y] == 2 || boardLook[x][y] == 3)
							ChangePos(x, y, BoardOfFigures, game);
						else
							MakeFiguresUnready(BoardOfFigures); //Jeœli nic nie wybraliœmy figury nie powinny byæ gotowe do ruchu
						if (game->state == WaitingForMove)
							game->state = WaitingForAction;
						FillBoard(boardLook);
					}
					else if (game->state == EndOfTheGame) {
						if(x > 250 && x < 750 && y > 200 && y < 250)
							initialisation(boardLook, BoardOfFigures, game); //Jeœli chcemy powtórzyæ gre
						else
							break;
					}		
					else if (game->state == UpdatePawnValue) {
						UpdatePawn(x, y, BoardOfFigures, game);
					}
				}
				
			}
		}
		// --------------------------------------------------------------
		// --------------------------------------------------------------
		//Czêœæ odpowiadaj¹ca za wrederowanie gry
		SDL_RenderClear(renderer);
		render(renderer, arrayOfSignTextures, arrayOfFigureTextures, boardLook, BoardOfFigures, game);
		SDL_RenderPresent(renderer);
		// --------------------------------------------------------------
		
	}
	// --------------------------------------------------------------
	//Czêœæ odpowiadaj¹ca za zwolnienie pamiêci
	free(game);
	destroyTextures(arrayOfFigureTextures, 12);
	destroyTextures(arrayOfSignTextures, 9);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	// --------------------------------------------------------------
	SDL_Quit();
	return 0;
}
