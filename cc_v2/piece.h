#pragma once
#include <vector>
#include "move.h"
#define WHITE 1
#define BLACK -1
#define EMPTY 0

class piece
{
public:
	piece() = delete;
	piece(char color) { this->color = color; }
	piece& operator=(const piece&);
	virtual std::vector<mov> gen_moves(unsigned)=0;
	virtual char show() = 0;
	virtual double value() = 0;

protected:
	 char color;

};
