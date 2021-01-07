#pragma once
#include "piece.h"
class pawn :public piece
{


public:
	pawn() = delete;
	pawn(unsigned char color) : piece(color) {};

	pawn& operator=(const pawn& other) { if (this != &other) this->color = other.color; return *this; };
	pawn* operator=(const pawn* other) { if (this != other) this->color = other->color; return this; };

	std::vector<mov>gen_moves(unsigned);
	void check_moves( std::vector<mov>& moves , std::vector<double> board_slice);
	char id() { if (color == WHITE) return 6 + 1; else return 1; };
	wchar_t show() { return 'p'; }
	double value() { return color*1; }
	
};
