#pragma once
#include "piece.h"
#include "move.h"
#include <vector>
class Board
{
public:
	Board();
	~Board();
	
private:

protected:
	std::vector<piece>chess_board;
	
};

Board::Board()
{
}

Board::~Board()
{
}