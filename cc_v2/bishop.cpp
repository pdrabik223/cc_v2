#include "bishop.h"

std::vector<mov> bishop::gen_moves(unsigned position)
{
	//white on bottom black on top
	std::vector<mov> moves;
	// 8 == width and height of board
	short px = position / 8, py = position % 8; // check with board borders 


	while (px > 0 && py > 0) {
		moves.push_back(mov(position, (--px) * 8 + (--py)));
	}

	while (px > 0 && py < 7) {
		moves.push_back(mov(position, (--px) * 8 + (++py)));
	}

	while (px < 7 && py < 7) {
		moves.push_back(mov(position, (++px) * 8 + (++py)));
	}

	while (px < 7 && py > 0) {
		moves.push_back(mov(position, (++px) * 8 + (--py)));
	}

	return moves;
}
