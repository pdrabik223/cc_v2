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

void bishop::check_moves(std::vector<mov>& moves, std::vector<double> board_slice)
{
	if (moves.empty())return;
	short px = moves[0].get_from() / 8, py = moves[0].get_from() % 8;
	std::vector<mov>  legal_moves;

	int i = 0, eraser = 0;

	for (; i < px - 1; i++)
	{
		if (board_slice[i] * color == 0) legal_moves.push_back(moves[i]);
		else if (board_slice[i] * color > 0) break;
		else {
			legal_moves.push_back(moves[i]); break;
		}
	}
	int j = i;
	for (; j < py - 1; j++) {
		if (board_slice[j] * color == 0) legal_moves.push_back(moves[j]);
		else if (board_slice[j] * color > 0) break;
		else {
			legal_moves.push_back(moves[j]); break;
		}
	}
	i = j;
	for (; i < 7 - px; i++)
	{
		if (board_slice[i] * color == 0) legal_moves.push_back(moves[i]);
		else if (board_slice[i] * color > 0) break;
		else {
			legal_moves.push_back(moves[i]); break;
		}
	}
	j = i;
	for (; j < 7 - py; j++) {
		if (board_slice[j] * color == 0) legal_moves.push_back(moves[j]);
		else if (board_slice[j] * color > 0) break;
		else {
			legal_moves.push_back(moves[j]); break;
		}
	}

	moves = legal_moves;


	// so moves is ordered kinda 
		// in a way that \
					\\	  \	


}
