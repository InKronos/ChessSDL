/**
 * @file BoardFunctions.h
 * @brief plik zawiekaj¹cy funkcje obsuguj¹ce logike programu dotycz¹ce dzia³añ na planszy
 */
#pragma once
#include "stdafx.h"

 /** Funkcja wype³niaj¹ca tablice figur figurami
  @param board tablica figur
  */
void CreateBoard(Figure board[8][8]);

/** Funkcja do zmieniania stanu z gotowego do ruchu na nie gotowe
 @param board tablica figur
 */
void MakeFiguresUnready(Figure board[8][8]);

/** Funkcja wype³niaj¹ca tablice kolorami planszy
 @param board tablica planszy
 */
void FillBoard(int board[8][8]);

/** Funkcja zamieniaj¹ca koordynaty myszki na odpowiadaj¹ce jej koordynaty tablicy dwuwymiarowej
 @param x po³orzenie na osi x
 @param y po³orzenie na osi y
 */
void GetPos(int* x, int* y);

/** Funkcja do kolorowania planszy na kolory opowiadj¹ce dostêpnym ruchom oraz przygotowuj¹ce figure do wykonania ruchu
 @param x aktualne po³orzenie figury w pierszym wymiarze tablicy
 @param y aktualne po³orzenie figury w drugim wymiarze tablicy
 @param newX po³orzenie figury na które figura ma siê przenieœæ w pierszym wymiarze tablicy
 @param newY po³orzenie figury na które figura ma siê przenieœæ w drugim wymiarze tablicy
 @param board tablica figur
 @param boardLook tablica widoku planszy
 @param toProcces zmienna powiadamiaj¹ca funkcje przez któr¹ ta funkcja zosta³a wywo³ana czy nie natrafi³a na jak¹œ przeszkode w danym kierunku
 */
void colorBoard(int x, int y, int newX, int newY, Figure board[8][8], int boardLook[8][8], bool* toProcess);