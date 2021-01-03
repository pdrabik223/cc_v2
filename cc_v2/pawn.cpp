#include "pawn.h"

std::vector<mov> pawn::gen_moves(unsigned position) {
	//white on bottom black on top
	std::vector<mov> moves;
	if (color==WHITE) {


		moves.push_back(mov(position, position - 8 -1));

		moves.push_back(mov(position,position - 8));

		moves.push_back(mov(position, position - 8 + 1));


		if(position/8 == 7) moves.push_back(mov(position, position - 16));



	}
	else {
		moves.push_back(mov(position, position + 8 - 1));

		moves.push_back(mov(position, position + 8));

		moves.push_back(mov(position, position + 8 + 1));


		if (position / 8 == 1) moves.push_back(mov(position, position + 16));


	}
	return moves;

}