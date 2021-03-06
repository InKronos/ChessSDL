/**
 * @file MovOfFigures.h
 * @brief plik z funkcjami obsugującymi ruchy figur 
 */
#pragma once
#include "stdafx.h"

/** Funkcja znajdująca zaznaczoną figure
 @param	x zmienna połorzenia myszki na osi x
 @param y zmienna połorzenia myszki na osi y
 @param board tablica figur
 @param boardLook tablica widku planszy
 @param game strutura maszyny stanów gry
 */
void FindPos(int x, int y, Figure board[8][8], int boardLook[8][8], Game *game);


/** Funkcja opowiadająca za ruchy pionka
 @param	x zmienna połorzenia w pierszym wymiarze
 @param y zmienna połorzenia w drugim wymiarze
 @param board tablica figur
 @param boardLook tablica widku planszy
 */
void MovOfPawn(int x, int y, Figure board[8][8], int boardLook[8][8]);

/** Funkcja opowiadająca za ruchy konia
 @param	x zmienna połorzenia w pierszym wymiarze
 @param y zmienna połorzenia w drugim wymiarze
 @param board tablica figur
 @param boardLook tablica widku planszy
 */
void MovOfKnight(int x, int y, Figure board[8][8], int boardLook[8][8]);

/** Funkcja opowiadająca za ruchy wieży
 @param	x zmienna połorzenia w pierszym wymiarze
 @param y zmienna połorzenia w drugim wymiarze
 @param board tablica figur
 @param boardLook tablica widku planszy
 */
void MovOfRook(int x, int y, Figure board[8][8], int boardLook[8][8]);

/** Funkcja opowiadająca za ruchy gońca
 @param	x zmienna połorzenia w pierszym wymiarze
 @param y zmienna połorzenia w drugim wymiarze
 @param board tablica figur
 @param boardLook tablica widku planszy
 */
void MovOfBishop(int x, int y, Figure board[8][8], int boardLook[8][8]);

/** Funkcja opowiadająca za ruchy króla
 @param	x zmienna połorzenia w pierszym wymiarze
 @param y zmienna połorzenia w drugim wymiarze
 @param board tablica figur
 @param boardLook tablica widku planszy
 */
void MovOfKing(int x, int y, Figure board[8][8], int boardLook[8][8]);

/** Funkcja opowiadająca za zmiane pozycji figury
 @param	x zmienna połorzenia w pierszym wymiarze
 @param y zmienna połorzenia w drugim wymiarze
 @param board tablica figur
 @param game strutura maszyny stanów gry
 */
void ChangePos(int x, int y, Figure board[8][8], Game *game);

/** Funkcja opowiadająca za ulepszenie pionka
 @param	x zmienna połorzenia na osi x
 @param y zmienna połorzenia na osi y
 @param board tablica figur
 @param game strutura maszyny stanów gry
 */
void UpdatePawn(int x, int y, Figure board[8][8], Game* game);

