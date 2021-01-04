#pragma once
#include "piece.h"
class queen : public piece
{
public:
	queen() = delete;
	queen(char color) : piece(color) {};
	std::vector<mov> gen_moves(unsigned);
	char show() { return 'q'; }
	double value() { return color * 9; }

private:

};
