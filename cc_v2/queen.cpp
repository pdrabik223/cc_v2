#include "queen.h"

std::vector<mov> queen::gen_moves(unsigned position )
{
	//white on bottom black on top
	std::vector<mov> moves;
	// 8 == width and height of board
	short px = position / 8, py = position % 8; // check with board borders 
	
	//bishup

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

	px = position / 8, py = position % 8;


	 // rook
	while (px > 0) {
		moves.push_back(mov(position, (--px) * 8 + py));
	}

	while (px < 7) {
		moves.push_back(mov(position, (--px) * 8 + py));
	}

	while (py < 7) {
		moves.push_back(mov(position, px * 8 + (++py)));
	}

	while (py > 0) {
		moves.push_back(mov(position, px * 8 + (--py)));
	}



	return moves;
}

void queen::check_moves(std::vector<mov>& moves, std::vector<double> board_slice)
{
	if (moves.empty())return;
	std::vector<mov> legal_moves;
	short px =moves[0].get_from()/ 8, py = moves[0].get_from() % 8; // check with board borders 

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
}
