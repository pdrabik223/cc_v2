#pragma once
#include "piece.h"
class rook :public piece
{
public:
	rook() = delete;
	rook(char color) :piece(color) {};
	rook& operator=(const rook& other) { if(this != &other) this->color = other.color; return *this; };
	rook* operator=(const rook* other) { if (this != other) this->color = other->color; return this; };

	std::vector<mov> gen_moves(unsigned);
	char show() { return 'r'; }
	double value() { return color*5;}
private:

};
