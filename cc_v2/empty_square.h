#pragma once
#include "piece.h"
class empty : public piece
{
public:
	empty(char color) :piece(color) {};

	std::vector<mov>gen_moves(unsigned position) { return std::vector<mov>(); };
	char id() { return 0; };
	wchar_t show() { return ' '; }
	double value() { return 0; }

};

