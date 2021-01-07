#pragma once
#include "piece.h"
class night:public piece
{
public:
	night(unsigned char color) :piece(color) {};
	night& operator=(const night& other) { if (this != &other) this->color = other.color; return *this; };
	night* operator=(const night* other) { if (this != other) this->color = other->color; return this; };

	std::vector<mov>gen_moves(unsigned);
	void check_moves(std::vector<mov>& moves, std::vector<double> board_slice);
	char id() { if (color == WHITE) return 6+ 2; else return 2 ; };
	wchar_t show() { return 'n'; }
	double value() { return color * 3; }
};
