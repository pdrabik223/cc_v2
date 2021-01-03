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
	piece(unsigned char color) { this->color = color; }
	piece& operator=(const piece& oter);
	virtual std::vector<mov> gen_moves(unsigned)=0;
	virtual char show() = 0;


protected:
	unsigned char color;

};
