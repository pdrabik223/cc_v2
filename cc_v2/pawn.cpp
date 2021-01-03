#include "pawn.h"

std::vector<mov> pawn::gen_moves(unsigned position) {
	//white on bottom black on top
	std::vector<mov> moves;
	// 8 == width and height of board
	short px = position / 8, py = position % 8; // check with board borders 
	if (color == WHITE) {


		if (!(bool)py) moves.push_back(mov(position, position - 8 - 1));
		//coz fuck you
		moves.push_back(mov(position, position - 8));

		if (py != 7) moves.push_back(mov(position, position - 8 + 1));


		if (px == 6) moves.push_back(mov(position, position - 16));



	}
	else {
		if (py != 0) moves.push_back(mov(position, position + 8 - 1));

		moves.push_back(mov(position, position + 8));

		if (py != 7)moves.push_back(mov(position, position + 8 + 1));


		if (px == 1) moves.push_back(mov(position, position + 16));


	}
	return moves;

}