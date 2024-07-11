#ifndef HELPER_HPP
#define HELPER_HPP
#include <string>
#include <vector>
enum class State
{
    kEmpty,
    kObstacle,
    kClosed,
    kPath,
    kStart,
    kFinish

};
void PrintBoard(std::vector<std::vector<State>> board);
bool ReadBoardFile(std::string inputfileDir, std::vector<std::vector<State>> &board);
#endif /* HELPER_HPP */
