/**
 * @file BoardFunctions.h
 * @brief plik zawiekaj�cy funkcje obsuguj�ce logike programu dotycz�ce dzia�a� na planszy
 */
#pragma once
#include "stdafx.h"

 /** Funkcja wype�niaj�ca tablice figur figurami
  @param board tablica figur
  */
void CreateBoard(Figure board[8][8]);

/** Funkcja do zmieniania stanu z gotowego do ruchu na nie gotowe
 @param board tablica figur
 */
void MakeFiguresUnready(Figure board[8][8]);

/** Funkcja wype�niaj�ca tablice kolorami planszy
 @param board tablica planszy
 */
void FillBoard(int board[8][8]);

/** Funkcja zamieniaj�ca koordynaty myszki na odpowiadaj�ce jej koordynaty tablicy dwuwymiarowej
 @param x po�orzenie na osi x
 @param y po�orzenie na osi y
 */
void GetPos(int* x, int* y);

/** Funkcja do kolorowania planszy na kolory opowiadj�ce dost�pnym ruchom oraz przygotowuj�ce figure do wykonania ruchu
 @param x aktualne po�orzenie figury w pierszym wymiarze tablicy
 @param y aktualne po�orzenie figury w drugim wymiarze tablicy
 @param newX po�orzenie figury na kt�re figura ma si� przenie�� w pierszym wymiarze tablicy
 @param newY po�orzenie figury na kt�re figura ma si� przenie�� w drugim wymiarze tablicy
 @param board tablica figur
 @param boardLook tablica widoku planszy
 @param toProcces zmienna powiadamiaj�ca funkcje przez kt�r� ta funkcja zosta�a wywo�ana czy nie natrafi�a na jak�� przeszkode w danym kierunku
 */
void colorBoard(int x, int y, int newX, int newY, Figure board[8][8], int boardLook[8][8], bool* toProcess);