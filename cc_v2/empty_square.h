#pragma once
#include "piece.h"
class empty : public piece
{
public:
	empty(char color) :piece(color) {};

	std::vector<mov>gen_moves(unsigned position) { return std::vector<mov>(); };
	char show() { return '_'; }
	double value() { return 0; }

};

