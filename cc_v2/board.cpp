#include "board.h"
#include <iostream>

Board::Board()
{
	//chess_board.reserve(64);

	chess_board[0] = new rook(BLACK);
	chess_board[1] = new night(BLACK);
	chess_board[2] = new  bishop(BLACK);
	chess_board[3] = new  queen(BLACK);
	chess_board[4] = new  king(BLACK);
	chess_board[5] = new bishop(BLACK);
	chess_board[6] = new  night(BLACK);
	chess_board[7] = new rook(BLACK);
	for (int i = 8; i < 16; i++) chess_board[i] = new pawn(BLACK);
	for (int i = 16; i < 48; i++) chess_board[i] = new empty(EMPTY);
	for (int i = 48; i < 56; i++) chess_board[i] = new pawn(WHITE);
	chess_board[56] = new rook(WHITE);
	chess_board[57] = new night(WHITE);
	chess_board[58] = new bishop(WHITE);
	chess_board[59] = new queen(WHITE);
	chess_board[60] = new king(WHITE);
	chess_board[61] = new bishop(WHITE);
	chess_board[62] = new night(WHITE);
	chess_board[63] = new rook(WHITE);
	
	/*
	chess_board.push_back(new rook(BLACK));
	chess_board.push_back(night(BLACK));
	chess_board.push_back(bishop(BLACK));
	chess_board.push_back(queen(BLACK));
	chess_board.push_back(king(BLACK));
	chess_board.push_back(bishop(BLACK));
	chess_board.push_back(night(BLACK));
	chess_board.push_back(rook(BLACK));
	for (int i = 8; i < 16; i++) chess_board.push_back(pawn(BLACK));
	for (int i = 16; i < 48; i++) chess_board.push_back(empty(EMPTY));
	for (int i = 48; i < 56; i++) chess_board.push_back(pawn(WHITE));
	chess_board.push_back(rook(WHITE));
	chess_board.push_back(night(WHITE));
	chess_board.push_back(bishop(WHITE));
	chess_board.push_back(queen(WHITE));
	chess_board.push_back(king(WHITE));
	chess_board.push_back(bishop(WHITE));
	chess_board.push_back(night(WHITE));
	chess_board.push_back(rook(WHITE));
	*/


	white_castle = false;
	black_castle = false;


}

std::vector<mov> Board::gen_moves_in_position(unsigned position)
{
	std::vector<mov> moves = chess_board[position]->gen_moves(position);


	return moves;
}

void Board::show()
{
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);

	bool flipper = true;


	for (int i = 0; i < 64; i++) {
		if (flipper) {

			if (chess_board[i]->value() >= 0)SetConsoleTextAttribute(hc, 8 + 12 * 16);
			else SetConsoleTextAttribute(hc, 1 + 12 * 16);

		}
		else {

			if (chess_board[i]->value() >= 0)SetConsoleTextAttribute(hc, 8 + 4 * 16);
			else SetConsoleTextAttribute(hc, 1 + 4 * 16);

		
		}
		flipper = !flipper;

		printf(" %c ", chess_board[i]->show());

		if (i % 8 == 7) {
			printf("\n");
			flipper = !flipper;

		}
	}



}
