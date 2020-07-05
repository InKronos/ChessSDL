/**
 * @file Figure.h
 * @brief plik struktury figur
 */
#pragma once
#include "stdafx.h"

/** Specjany typ dla figur */
typedef enum Type {
	None,
	Pawn,
	Rook,
	Knight,
	Bishop,
	Queen,
	King
} Type;

/** Struktura Figury */
typedef struct Figure
{
	int position_x; ///< po³orzenie figury na osi x
	int position_y; ///< po³orzenie figury na osi y
	Type type; ///< typ figury
	bool player; ///< do którego gracza nale¿y figura
	bool readyToMove; ///< czy figura jest gotowa wykonaæ ruch
} Figure;


