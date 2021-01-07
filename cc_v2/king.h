#pragma once
#include "piece.h"
class king :public piece
{
public:
	king() = delete;
	king(unsigned char color) :piece(color) {};
	king(const king& other) { this->color = other.color; }
	king& operator=(const king& other) { if (this != &other) this->color = other.color; return *this; };
	 
	 std::vector<mov> gen_moves(unsigned) ;
	 void check_moves(std::vector<mov>& moves, std::vector<double> board_slice);
	 char id() { if (color == WHITE) return 6+ 6; else return 6; };
	 wchar_t show() { return 'k'; };
	 double value() { return color*1000.0;  }
};
