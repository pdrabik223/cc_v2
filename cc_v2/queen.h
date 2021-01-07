#pragma once
#include "piece.h"
class queen : public piece
{
public:
	queen() = delete;
	queen(char color) : piece(color) {};
	queen& operator=(const queen& other) { if (this != &other) this->color = other.color; return *this; };
	std::vector<mov> gen_moves(unsigned);
	void check_moves(std::vector<mov>& moves, std::vector<double> board_slice);
	char id() { if (color == WHITE) return 6+5; else return 5; };
	wchar_t show() { return 'q'; }
	double value() { return color * 9; }

private:

};
