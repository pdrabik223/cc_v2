#pragma once
#include "piece.h"

class bishop :public piece
{
public:
	bishop() = delete;
	bishop(char color) :piece(color) {};
	bishop& operator=(const bishop& other) { if (this != &other) this->color = other.color; return *this; };
	bishop* operator=(const bishop* other) { if (this != other) this->color = other->color; return this; };
	std::vector<mov>gen_moves(unsigned);

	void check_moves(std::vector<mov>& moves, std::vector<double> board_slice) ;
	char id() { if (color == WHITE) return  6 + 3; else return 3; };

	wchar_t show() { return 'b'; }
	double value() { return color*3.1; }


};
