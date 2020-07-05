/**
 * @file Game.h
 * @brief plik ze stutur� gry oraz funkcjami dotycz�cych gry
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

/** Struktura maszyny stan�w gry */
typedef struct Game {
	bool player; ///< zmienna okre�laj�ca aktualnego gracza
	GameState state; ///< zmienna stan�w gry
} Game;

/** Funkcja do inicjalizacji zmiennych
 @param boardLook tablica widku planszy
 @param BoardOfFigures tablica figur
 @param game strutura maszyny stan�w gry
 */
void initialisation(int BoardLook[8][8], Figure BoardOfFigures[8][8], Game * game);


/** Funkcja renderowania wszystkich obiekt�w
 @param	renderer zmienna potrzebna do renderowania widoku
 @param arrayOfSignTextures tablica z teksturami napis�w
 @param player zmiena logiczna powiadamiaj�ca program do kogo nale�y tura
 @param arrayOfTextures tablica z teksturami figur
 @param boardLook tablica widku planszy
 @param BoardOfFigures tablica figur
 @param game strutura maszyny stan�w gry
 */
void render(SDL_Renderer* renderer, SDL_Texture* arrayOfSignTextures[9], SDL_Texture* arrayOfTextures[12], int boardLook[8][8], Figure BoardOfFigures[8][8], Game* game);