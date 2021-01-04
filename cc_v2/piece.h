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
	piece& operator=(const piece&);
 //std::vector<mov> gen_moves(unsigned);
 char show() { return ' '; };
	
 double value() { return 0; };


protected:
	 char color;

};
