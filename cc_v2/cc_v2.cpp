// cc_v2.cpp: definiuje punkt wejścia dla aplikacji.
//
/*
#include "cc_v2.h"
#include "board.h"


int main()
{

	//for now in console
	//later will add some js ui
	//for now console
	//Board first;
	//first.show();

	//std::cout << first.gen_snapshot();





	return 0;
}
*/
#include <array>
#include <cstdio>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <string>
#include <vector>
#include <chrono>

enum Type { Pawn, Rook, Queen, King, Knight, Bishop };

enum Color { White, Black, None };

struct PieceFull {
	Color color;
	Type type;
};

typedef char Piece;
typedef std::array<Piece, 64> Board;
typedef std::array<PieceFull, 64> BoardFull;

int pow2(int a) {
	int res = 1;
	res = res << a;
	return res;
}

#define DoNotOptimize(val) show(val[0])// << std::endl

std::array<unsigned long, 4> update_arr(std::array<unsigned long, 4> board,
	char from, char to) {

	char qfrom = from >> 4, qto = to >> 4;

	std::array<unsigned long, 4> new_board = board;

	unsigned long temp = (board[qfrom]);
	temp = temp << (4 * (15 - from));
	temp = temp >> 60;
	temp = temp << (4 * to);

	unsigned long mask = ULONG_MAX;

	for (int i = 0; i < 4; i++)
		mask -= pow2(from + i); // pow(2,to+i);

	new_board[qfrom] &= mask;

	mask = ULONG_MAX;
	for (int i = 0; i < 4; i++)
		mask -= pow2(to + i); // pow(2,to+i);

	new_board[qto] = new_board[qto] & mask;

	new_board[qto] += temp;

	return new_board;
}

Board update_arr2(Board board, int from, int to) {
	Board new_board = board;
	new_board[to] = new_board[from];
	new_board[from] = 0;
	return new_board;
}

BoardFull update_arr3(BoardFull board, int from, int to) {
	BoardFull new_board = board;
	new_board[to] = new_board[from];
	new_board[from] = PieceFull({ Color::None, Type::Pawn });
	return new_board;
}

std::string show(unsigned long a) { return "P1: " + std::to_string(a); }

std::string show(Piece a) { return "P2: " + std::to_string(a); }

std::string show(PieceFull a) { return "M1: " + std::to_string(a.color); }

int main() {

	unsigned lenght = 100000;

	std::array<unsigned long, 4> board({ 1, 0, 0, 0 });
	int from = 0;
	int to = 1;


	DoNotOptimize(board);
	auto t1 = std::chrono::high_resolution_clock::now();

	for (auto i = 0; i < lenght; i++) {
		
		auto new_board = update_arr(board, from, to);
			DoNotOptimize(new_board);
	}
	auto t2 = std::chrono::high_resolution_clock::now();

		std::clog << "pioter1: " << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << "mili" << std::endl;

	{
		Board board;
		for (int i = 0; i < 64; i++) {
			board[i] = (Piece)0;
		}

		int from = 1;
		int to = 50;

		DoNotOptimize(board);
		auto t1 = std::chrono::high_resolution_clock::now();


		for (auto i = 0; i < lenght; i++) {

			auto new_board = update_arr2(board, from, to);

			DoNotOptimize(new_board);

		}
		auto t2 = std::chrono::high_resolution_clock::now();


		std::clog << "pioter2: " << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << "mili" << std::endl;

	}

	{
		BoardFull board;
		for (int i = 0; i < 64; i++) {
			board[i] = PieceFull({ Color::None, Type::Pawn });
		}
		int from = 1;
		int to = 50;

		DoNotOptimize(board);
		auto t1 = std::chrono::high_resolution_clock::now();

		for (auto i = 0; i < lenght; i++) {
			auto new_board = update_arr3(board, from, to);
			DoNotOptimize(new_board);
		}	
		auto t2 = std::chrono::high_resolution_clock::now();
		std::clog << "mati: " << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << "mili" << std::endl;

	}





}
