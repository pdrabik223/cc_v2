#include "board.h"

Board::Board()
{
	chess_board.reserve(64);
	chess_board[0] = rook(BLACK);
	chess_board[1] = night(BLACK);
	chess_board[2] = bishop(BLACK);
	chess_board[3] = queen(BLACK);
	chess_board[4] = king(BLACK);
	chess_board[5] = bishop(BLACK);
	chess_board[6] = night(BLACK);
	chess_board[7] = rook(BLACK);
	for(int i=8;i<16;i++) chess_board[i] = pawn(BLACK);
	for (int i = 16; i < 48; i++) chess_board[i] = empty(EMPTY);
	for (int i = 48; i < 56; i++) chess_board[i] = pawn(WHITE);
	chess_board[56] = rook(WHITE);
	chess_board[57] = night(WHITE);
	chess_board[58] = bishop(WHITE);
	chess_board[59] = queen(WHITE);
	chess_board[60] = king(WHITE);
	chess_board[61] = bishop(WHITE);
	chess_board[62] = night(WHITE);
	chess_board[63] = rook(WHITE);
	white_castle = false;
	black_castle = false;


}

void Board::show()
{
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
	
	bool flipper = true;

	for (int i = 0; i < 64; i++) {
		if (flipper) {

			if(chess_board[i].value() >=0)SetConsoleTextAttribute(hc, 8 + 12 * 16);
			else SetConsoleTextAttribute(hc, 1 + 12 * 16);

		}
		else {

			if (chess_board[i].value() >= 0)SetConsoleTextAttribute(hc, 8 + 4 * 16);
			else SetConsoleTextAttribute(hc, 1 + 4 * 16);

			printf("%c",chess_board[i].show());



		}
		!flipper;
		printf("%c", chess_board[i].show());

		if (i % 8 == 7)printf("\n");
	}



}
