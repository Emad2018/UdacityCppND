/**
 * @file helper.cpp
 * @author Abdelrahman Emad (a.emad02018@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-02
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include "helper.hpp"

static std::vector<State> ParseLine(std::string line);
static std::string CellString(State cell);
/**
 * @brief take a state cell and return a shape for the state
 *
 * @param cell of type State
 * @return std::string
 */
static std::string CellString(State cell)
{
    std::string result;
    switch (cell)
    {
    case State::kObstacle:
        result = "⛰️   ";
        break;
    case State::kStart:
        result = "🚦 ";
        break;
    case State::kFinish:
        result = "🏁 ";
        break;
    case State::kPath:
        result = "🚗 ";
        break;
    default:
        result = "0  ";
        break;
    }
    return result;
}
/**
 * @brief ParseLine convert a row of the input board from string to vector of states
 *
 * @param line of string which is a row of the input board
 * @return std::vector<State> represent a row of the input board
 */
static std::vector<State> ParseLine(std::string line)
{
    std::vector<State> result;
    std::istringstream my_stream(line);
    int number;
    while (my_stream >> number)
    {
        if (true == number)
        {
            result.push_back(State::kObstacle);
        }
        else
        {
            result.push_back(State::kEmpty);
        }
    }
    return result;
}
/**
 * @brief Read aBoard text File
 *
 * @param inputfileDir file directory
 * @param board        ref to the board
 * @return true        read was successful
 * @return false       read failed
 */
bool ReadBoardFile(std::string inputfileDir, std::vector<std::vector<State>> &board)
{

    // Open the input file
    std::ifstream inputFile(inputfileDir);
    // Check if the file is successfully opened
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening the file!" << std::endl;
        return false;
    }

    std::string line; // Declare a string variable to store each
                      // line of the file

    // Read each line of the file

    while (getline(inputFile, line))
    {
        board.push_back(ParseLine(line)); // Print the current line
    }

    // Close the file
    inputFile.close();
    return true;
}
/**
 * @brief print the input board
 *
 * @param board
 */
void PrintBoard(std::vector<std::vector<State>> board)
{
    for (int row = 0; row < board.size(); ++row)
    {
        for (int col = 0; col < board[0].size(); ++col)
        {
            std::cout << CellString(board[row][col]) << " ";
        }
        std::cout << std::endl;
    }
}