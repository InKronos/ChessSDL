/**
 * @file RenderFunctions.h
 * @brief plik zawiekaj¹cy funkcje potrzebne do wyœwietlania obiektów
 */
#pragma once
#include "stdafx.h"

 /** Funkcja do pobierania funkcji z pliku
  @param	file ³añcuch znaków zawieraj¹cy nazwe pliku
  @param	renderer zmienna potrzebna do renderowania widoku
  @return funkcja zwraca teksture
  */
SDL_Texture* LoadTexture(char* file, SDL_Renderer* renderer);

/** Funkcja do pobierania tekstur figur 
 @param	arrayOfTextures tablica zawieraj¹ca tekstury figur
 @param	renderer zmienna potrzebna do renderowania widoku
 */
void getFigureTextures(SDL_Texture* arrayOfTextures[12], SDL_Renderer* renderer);

/** Funkcja do pobierania tekstur napisów
 @param	arrayOfTextures tablica zawieraj¹ca tekstury napisów
 @param	renderer zmienna potrzebna do renderowania widoku
 */
void getSignTextures(SDL_Texture* arrayOfTextures[9], SDL_Renderer* renderer);

/** Funkcja do zwalniania tekstur z pamiêci
 @param	arrayOfTextures tablica zawieraj¹ca tekstury figur
 @param	size rozmiar tablicy
 */
void destroyTextures(SDL_Texture* arrayOfTextures[], int size);

/** Funkcja wyœwietlania planszy
 @param	renderer zmienna potrzebna do renderowania widoku
 @param	board tablica widoku planszy
 */
void RenderBoard(SDL_Renderer* renderer, int board[8][8]);

/** Funkcja wyœwietlania figur
 @param	renderer zmienna potrzebna do renderowania widoku
 @param	board tablica widoku i po³orzenia figur
 @param arrayOfTextures tablica z teksturami figur
 */
void RenderFigures(SDL_Renderer* renderer, Figure board[8][8], SDL_Texture* arrayOfTextures[12]);

/** Funkcja wyœwietlania napisów tury gracza
 @param	renderer zmienna potrzebna do renderowania widoku
 @param arrayOfTextures tablica z teksturami napisów
 @param game strutura maszyny stanów gry
 */
void RenderSigns(SDL_Renderer* renderer, SDL_Texture* arrayOfTextures[9], Game * game);

/** Funkcja wyœwietlania napisów koñcowych
 @param	renderer zmienna potrzebna do renderowania widoku
 @param arrayOfTextures tablica z teksturami napisów
 @param game strutura maszyny stanów gry
 */
void RenderEndOfTheGame(SDL_Renderer* renderer, SDL_Texture* arrayOfTextures[9], Game * game);

/** Funkcja wyœwietlania napisów do ulepszenia pionka
 @param	renderer zmienna potrzebna do renderowania widoku
 @param arrayOfTextures tablica z teksturami napisów
 */
void RenderUpdatePawn(SDL_Renderer* renderer, SDL_Texture* arrayOfTextures[9]);