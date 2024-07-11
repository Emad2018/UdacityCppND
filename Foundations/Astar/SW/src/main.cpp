#include <vector>
#include "helper.hpp"
#include "Astar.hpp"

int main()
{
    int start[2] = {0, 0};
    int End[2] = {4, 5};
    std::vector<std::vector<State>> board;

    (void)ReadBoardFile("../../SW/board/board.txt", board);
    board = Search(board, start, End);
    PrintBoard(board);
    return 0;
}