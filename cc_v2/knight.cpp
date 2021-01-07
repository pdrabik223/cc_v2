#include "knight.h"
std::vector<mov>night::gen_moves(unsigned position) {

	std::vector<mov> moves;
	// 8 == width and height of board
	short px = position / 8, py = position % 8; // check with board borders 

	//	1	2
	//3		  4
	//	  n
	//5		  6
	//	7	8


	// i'm so sorry
	if (px != 0) {

		if (px != 1) {

			if (py != 0) { // 1
				moves.push_back(mov(position, position - 16 - 1));
			}
			if (py != 7) { // 2
				moves.push_back(mov(position, position - 16 + 1));
			}
		}


		if (py != 1) { // 3
			moves.push_back(mov(position, position - 8 - 2));
		}
		if (py != 6) { // 4
			moves.push_back(mov(position, position - 8 + 2));
		}
	}

	 if (px != 7) {

		if (py != 1) { // 5
			moves.push_back(mov(position, position + 8 - 2));
		}
		if (py != 6) { // 6
			moves.push_back(mov(position, position + 8 + 2));
		}


		if (px != 6) {
			if (py != 0) { // 7
				moves.push_back(mov(position, position + 16 - 1));
			}
			if (py != 7) { // 8
				moves.push_back(mov(position, position + 16 + 1));
			}
		}
	}

	return moves;

}

void night::check_moves(std::vector<mov>& moves, std::vector<double> board_slice)
{

	std::vector<mov> check_moves;
	for (int i = 0; i < moves.size(); i++)
		if (board_slice[i] * color >= 0)
			check_moves.push_back(moves[i]);

	moves = check_moves;

}
