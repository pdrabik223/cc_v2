#pragma once
#include "piece.h"
class pawn:public piece
{


public:
	pawn(unsigned char color ): piece(color) {};
	std::vector<mov>gen_moves(unsigned);
	char show() { return 'p'; }
};
