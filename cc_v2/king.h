#pragma once
#include "piece.h"
class king :public piece
{
public:
	king(unsigned char color) :piece(color) {};
	 std::vector<mov> gen_moves(unsigned) ;
	 char show() { return 'k'; };
};
