#pragma once
#include "piece.h"

class bishop :public piece
{
public:
	bishop() = delete;
	bishop(char color) :piece(color) {};
	std::vector<mov>gen_moves(unsigned);
	char show() { return 'b'; }
	double value() { return 3.1; }


};
