#pragma once
#include "piece.h"
class night:public piece
{
public:
	night(unsigned char color) :piece(color) {};
	std::vector<mov>gen_moves(unsigned);
	char show() { return 'n'; }
	double value() { return color * 3; }
};
