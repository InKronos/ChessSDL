/**
 * @file MovOfFigures.h
 * @brief plik z funkcjami obsuguj�cymi ruchy figur 
 */
#pragma once
#include "stdafx.h"

/** Funkcja znajduj�ca zaznaczon� figure
 @param	x zmienna po�orzenia myszki na osi x
 @param y zmienna po�orzenia myszki na osi y
 @param board tablica figur
 @param boardLook tablica widku planszy
 @param game strutura maszyny stan�w gry
 */
void FindPos(int x, int y, Figure board[8][8], int boardLook[8][8], Game *game);


/** Funkcja opowiadaj�ca za ruchy pionka
 @param	x zmienna po�orzenia w pierszym wymiarze
 @param y zmienna po�orzenia w drugim wymiarze
 @param board tablica figur
 @param boardLook tablica widku planszy
 */
void MovOfPawn(int x, int y, Figure board[8][8], int boardLook[8][8]);

/** Funkcja opowiadaj�ca za ruchy konia
 @param	x zmienna po�orzenia w pierszym wymiarze
 @param y zmienna po�orzenia w drugim wymiarze
 @param board tablica figur
 @param boardLook tablica widku planszy
 */
void MovOfKnight(int x, int y, Figure board[8][8], int boardLook[8][8]);

/** Funkcja opowiadaj�ca za ruchy wie�y
 @param	x zmienna po�orzenia w pierszym wymiarze
 @param y zmienna po�orzenia w drugim wymiarze
 @param board tablica figur
 @param boardLook tablica widku planszy
 */
void MovOfRook(int x, int y, Figure board[8][8], int boardLook[8][8]);

/** Funkcja opowiadaj�ca za ruchy go�ca
 @param	x zmienna po�orzenia w pierszym wymiarze
 @param y zmienna po�orzenia w drugim wymiarze
 @param board tablica figur
 @param boardLook tablica widku planszy
 */
void MovOfBishop(int x, int y, Figure board[8][8], int boardLook[8][8]);

/** Funkcja opowiadaj�ca za ruchy kr�la
 @param	x zmienna po�orzenia w pierszym wymiarze
 @param y zmienna po�orzenia w drugim wymiarze
 @param board tablica figur
 @param boardLook tablica widku planszy
 */
void MovOfKing(int x, int y, Figure board[8][8], int boardLook[8][8]);

/** Funkcja opowiadaj�ca za zmiane pozycji figury
 @param	x zmienna po�orzenia w pierszym wymiarze
 @param y zmienna po�orzenia w drugim wymiarze
 @param board tablica figur
 @param game strutura maszyny stan�w gry
 */
void ChangePos(int x, int y, Figure board[8][8], Game *game);

/** Funkcja opowiadaj�ca za ulepszenie pionka
 @param	x zmienna po�orzenia na osi x
 @param y zmienna po�orzenia na osi y
 @param board tablica figur
 @param game strutura maszyny stan�w gry
 */
void UpdatePawn(int x, int y, Figure board[8][8], Game* game);

