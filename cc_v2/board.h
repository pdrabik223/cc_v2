#pragma once
#include "empty_square.h"
#include "pawn.h"
#include "knight.h"
#include "bishop.h"
#include "rook.h"
#include "queen.h"
#include "king.h"
#include "move.h"

#include <Windows.h>
#include <conio.h>

#include <vector>
class Board
{
public:
	Board();
	double evaluate();
	
	std::vector<mov> gen_moves_in_position(unsigned);

	void show();
protected:
	piece* chess_board[64];
	bool white_castle;
	bool black_castle;

};
