#pragma once
#include "piece.h"
class rook :public piece
{
public:
	rook() = delete;
	rook(char color) :piece(color) {};
	std::vector<mov> gen_moves(unsigned);
	char show() { return 'r'; }
	double value() { return color*5;}
private:

};
