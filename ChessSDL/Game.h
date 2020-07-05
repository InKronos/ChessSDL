/**
 * @file Game.h
 * @brief plik ze stutur¹ gry oraz funkcjami dotycz¹cych gry
 */
#pragma once
#include "stdafx.h"

/** Stany gry */
typedef enum GameState {
	WaitingForAction,
	WaitingForMove,
	UpdatePawnValue,
	EndOfTheGame
} GameState;

/** Struktura maszyny stanów gry */
typedef struct Game {
	bool player; ///< zmienna okreœlaj¹ca aktualnego gracza
	GameState state; ///< zmienna stanów gry
} Game;

/** Funkcja do inicjalizacji zmiennych
 @param boardLook tablica widku planszy
 @param BoardOfFigures tablica figur
 @param game strutura maszyny stanów gry
 */
void initialisation(int BoardLook[8][8], Figure BoardOfFigures[8][8], Game * game);


/** Funkcja renderowania wszystkich obiektów
 @param	renderer zmienna potrzebna do renderowania widoku
 @param arrayOfSignTextures tablica z teksturami napisów
 @param player zmiena logiczna powiadamiaj¹ca program do kogo nale¿y tura
 @param arrayOfTextures tablica z teksturami figur
 @param boardLook tablica widku planszy
 @param BoardOfFigures tablica figur
 @param game strutura maszyny stanów gry
 */
void render(SDL_Renderer* renderer, SDL_Texture* arrayOfSignTextures[9], SDL_Texture* arrayOfTextures[12], int boardLook[8][8], Figure BoardOfFigures[8][8], Game* game);