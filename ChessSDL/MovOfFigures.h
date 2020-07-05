/**
 * @file MovOfFigures.h
 * @brief plik z funkcjami obsuguj¹cymi ruchy figur 
 */
#pragma once
#include "stdafx.h"

/** Funkcja znajduj¹ca zaznaczon¹ figure
 @param	x zmienna po³orzenia myszki na osi x
 @param y zmienna po³orzenia myszki na osi y
 @param board tablica figur
 @param boardLook tablica widku planszy
 @param game strutura maszyny stanów gry
 */
void FindPos(int x, int y, Figure board[8][8], int boardLook[8][8], Game *game);


/** Funkcja opowiadaj¹ca za ruchy pionka
 @param	x zmienna po³orzenia w pierszym wymiarze
 @param y zmienna po³orzenia w drugim wymiarze
 @param board tablica figur
 @param boardLook tablica widku planszy
 */
void MovOfPawn(int x, int y, Figure board[8][8], int boardLook[8][8]);

/** Funkcja opowiadaj¹ca za ruchy konia
 @param	x zmienna po³orzenia w pierszym wymiarze
 @param y zmienna po³orzenia w drugim wymiarze
 @param board tablica figur
 @param boardLook tablica widku planszy
 */
void MovOfKnight(int x, int y, Figure board[8][8], int boardLook[8][8]);

/** Funkcja opowiadaj¹ca za ruchy wie¿y
 @param	x zmienna po³orzenia w pierszym wymiarze
 @param y zmienna po³orzenia w drugim wymiarze
 @param board tablica figur
 @param boardLook tablica widku planszy
 */
void MovOfRook(int x, int y, Figure board[8][8], int boardLook[8][8]);

/** Funkcja opowiadaj¹ca za ruchy goñca
 @param	x zmienna po³orzenia w pierszym wymiarze
 @param y zmienna po³orzenia w drugim wymiarze
 @param board tablica figur
 @param boardLook tablica widku planszy
 */
void MovOfBishop(int x, int y, Figure board[8][8], int boardLook[8][8]);

/** Funkcja opowiadaj¹ca za ruchy króla
 @param	x zmienna po³orzenia w pierszym wymiarze
 @param y zmienna po³orzenia w drugim wymiarze
 @param board tablica figur
 @param boardLook tablica widku planszy
 */
void MovOfKing(int x, int y, Figure board[8][8], int boardLook[8][8]);

/** Funkcja opowiadaj¹ca za zmiane pozycji figury
 @param	x zmienna po³orzenia w pierszym wymiarze
 @param y zmienna po³orzenia w drugim wymiarze
 @param board tablica figur
 @param game strutura maszyny stanów gry
 */
void ChangePos(int x, int y, Figure board[8][8], Game *game);

/** Funkcja opowiadaj¹ca za ulepszenie pionka
 @param	x zmienna po³orzenia na osi x
 @param y zmienna po³orzenia na osi y
 @param board tablica figur
 @param game strutura maszyny stanów gry
 */
void UpdatePawn(int x, int y, Figure board[8][8], Game* game);

