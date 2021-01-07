#include "king.h"

std::vector<mov> king::gen_moves(unsigned position)// is in range 0-64
{
    std::vector<mov> moves;
    // 8 == width and height of board 
    short px = position / 8, py = position % 8; // check with board borders 
    // 1  2  3 
    // 4  k  5     k == position 
    // 6  7  8
    
    if (px != 0) {// in case of k being on first row from top

        if (py != 0) moves.push_back(mov(position, position - 8 - 1)); // 1
        moves.push_back(mov(position, position - 8)); // 2
        if (py != 7) moves.push_back(mov(position, position - 8 + 1)); // 3
    }
    if (py != 0) moves.push_back(mov(position, position - 1)); // 4
    if (py != 7) moves.push_back(mov(position, position + 1)); // 5

    if (px != 7) {// in case of k being on first row from bottom
        if (py != 0) moves.push_back(mov(position, position + 8 - 1)); // 6
        moves.push_back(mov(position, position + 8)); // 7
        if (py != 7) moves.push_back(mov(position, position + 8 + 1)); // 8
    }


    return moves;

}

void king::check_moves(std::vector<mov>& moves, std::vector<double> board_slice)
{
    std::vector<mov> check_moves;
    for (int i = 0; i < moves.size(); i++)
        if (board_slice[i] * color >= 0)
            check_moves.push_back(moves[i]);


    // tu jeszcze czeba wciepaæ szach ehhhhhhhhhhhhhhhh
    // hhhhh
    moves = check_moves;


}
