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
	void check_moves(std::vector<mov>& moves, std::vector<double> board_slice);
	char id() { if (color == WHITE) return 6+4; else return 4; };
	wchar_t show() { return 'r'; }
	double value() { return color*5;}
private:

};
