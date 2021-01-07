#pragma once
#include <vector>
#include "move.h"
#define WHITE 1
#define BLACK -1
#define EMPTY 0

class piece
{
public:
	piece() { color = EMPTY; };
	piece(char color) { this->color = color; }
	piece& operator=(const piece& other) { if (this != &other) this->color = other.color; return *this; };
	piece* operator=(const piece* other) { if (this != other) this->color = other->color; return this; };
	virtual void check_moves(std::vector<mov>& moves, std::vector<double> board_slice){ return; };

	virtual std::vector<mov> gen_moves(unsigned position) { return std::vector<mov>(); };
	virtual char id() { return 0; };
	virtual wchar_t show() { return '_'; };
	virtual	double value() { return 0; };


protected:
	 char color;

};
