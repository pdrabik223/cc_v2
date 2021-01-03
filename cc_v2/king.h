#pragma once
#include "piece.h"
class king :public piece
{
public:
	king() = delete;
	king(unsigned char color) :piece(color) {};
	 std::vector<mov> gen_moves(unsigned) ;
	 char show() { return 'k'; };
	 double value() { return color*1000.0;  }
};
