/**
 * @file RenderFunctions.h
 * @brief plik zawiekaj�cy funkcje potrzebne do wy�wietlania obiekt�w
 */
#pragma once
#include "stdafx.h"

 /** Funkcja do pobierania funkcji z pliku
  @param	file �a�cuch znak�w zawieraj�cy nazwe pliku
  @param	renderer zmienna potrzebna do renderowania widoku
  @return funkcja zwraca teksture
  */
SDL_Texture* LoadTexture(char* file, SDL_Renderer* renderer);

/** Funkcja do pobierania tekstur figur 
 @param	arrayOfTextures tablica zawieraj�ca tekstury figur
 @param	renderer zmienna potrzebna do renderowania widoku
 */
void getFigureTextures(SDL_Texture* arrayOfTextures[12], SDL_Renderer* renderer);

/** Funkcja do pobierania tekstur napis�w
 @param	arrayOfTextures tablica zawieraj�ca tekstury napis�w
 @param	renderer zmienna potrzebna do renderowania widoku
 */
void getSignTextures(SDL_Texture* arrayOfTextures[9], SDL_Renderer* renderer);

/** Funkcja do zwalniania tekstur z pami�ci
 @param	arrayOfTextures tablica zawieraj�ca tekstury figur
 @param	size rozmiar tablicy
 */
void destroyTextures(SDL_Texture* arrayOfTextures[], int size);

/** Funkcja wy�wietlania planszy
 @param	renderer zmienna potrzebna do renderowania widoku
 @param	board tablica widoku planszy
 */
void RenderBoard(SDL_Renderer* renderer, int board[8][8]);

/** Funkcja wy�wietlania figur
 @param	renderer zmienna potrzebna do renderowania widoku
 @param	board tablica widoku i po�orzenia figur
 @param arrayOfTextures tablica z teksturami figur
 */
void RenderFigures(SDL_Renderer* renderer, Figure board[8][8], SDL_Texture* arrayOfTextures[12]);

/** Funkcja wy�wietlania napis�w tury gracza
 @param	renderer zmienna potrzebna do renderowania widoku
 @param arrayOfTextures tablica z teksturami napis�w
 @param game strutura maszyny stan�w gry
 */
void RenderSigns(SDL_Renderer* renderer, SDL_Texture* arrayOfTextures[9], Game * game);

/** Funkcja wy�wietlania napis�w ko�cowych
 @param	renderer zmienna potrzebna do renderowania widoku
 @param arrayOfTextures tablica z teksturami napis�w
 @param game strutura maszyny stan�w gry
 */
void RenderEndOfTheGame(SDL_Renderer* renderer, SDL_Texture* arrayOfTextures[9], Game * game);

/** Funkcja wy�wietlania napis�w do ulepszenia pionka
 @param	renderer zmienna potrzebna do renderowania widoku
 @param arrayOfTextures tablica z teksturami napis�w
 */
void RenderUpdatePawn(SDL_Renderer* renderer, SDL_Texture* arrayOfTextures[9]);