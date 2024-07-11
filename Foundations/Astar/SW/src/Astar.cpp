/**
 * @file Astar.cpp
 * @author Abdelrahman Emad (a.emad02018@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-02
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <vector>
#include <math.h>
#include <algorithm>
#include "helper.hpp"
#include "Astar.hpp"

static void AddToOpen(int x, int y, int g, int h, std::vector<std::vector<int>> &openNodes,
                      std::vector<std::vector<State>> &grid);
static int Heuristic(int x1, int y1, int x2, int y2);
static bool Compare(std::vector<int> firstNode, std::vector<int> secondNode);
static void CellSort(std::vector<std::vector<int>> *openNode);
static bool CheckValidCell(int x, int y, std::vector<std::vector<State>> &grid);
static void ExpandNeighbors(std::vector<int> currentNode, int end[2], std::vector<std::vector<int>> &openNodes,
                            std::vector<std::vector<State>> &grid);
/**
 * @brief Search the path between a start point and end point.
 *
 * @param Grid
 * @param Start
 * @param End
 * @return std::vector<std::vector<State>>
 */
std::vector<std::vector<State>> Search(std::vector<std::vector<State>> Grid, int Start[2], int End[2])
{
    int x1, y1, x2, y2, g, h;
    std::vector<std::vector<int>> openNodes;

    x1 = Start[0];
    y1 = Start[1];
    x2 = End[0];
    y2 = End[1];
    g = 0;
    h = Heuristic(x1, y1, x2, y2);

    AddToOpen(x1, y1, g, h, openNodes, Grid);

    // while open vector is non empty {
    while (openNodes.size())
    {

        // Sort the open list by calling `CellSort`. `CellSort` method will sort the open list in a descending order to have the node with the lowest heuristic value at the end of the vector.

        // When you call the `CellSort` method, you will need to pass the memory address of the open vector like that: CellSort(&open) because the argument of the CellSort method is a pointer to a vector.
        CellSort(&openNodes);
        // get the last node from the open vector using the '.back()` method and save it to the variable `current_node`.
        std::vector<int> current_node = openNodes.back();
        // remove the last node from the open vector using the`.pop_back()` method.
        openNodes.pop_back();
        // Get the x and y values from the `current_node`,
        //  and set grid[x][y] to kPath.
        x1 = current_node[0];
        y1 = current_node[1];
        Grid[x1][y1] = State::kPath;
        // Check if you've reached the goal. If so, return grid.
        if (x1 == x2 && y1 == y2)
        {
            Grid[Start[0]][Start[1]] = State::kStart;
            Grid[x1][y1] = State::kFinish;
            return Grid;
        }
        // If we're not done, expand search to current node's neighbors. This step will be completed in a later quiz.
        // ExpandNeighbors
        else
        {
            ExpandNeighbors(current_node, End, openNodes, Grid);
        }
    }

    return Grid;
}
/**
 * @brief  Calculate the H value between two points
 *
 * @param x1
 * @param y1
 * @param x2
 * @param y2
 * @return int
 */
static int Heuristic(int x1, int y1, int x2, int y2)
{
    return abs(x2 - x1) + abs(y2 - y1);
}
/**
 * @brief add a point to open node list
 *
 * @param x
 * @param y
 * @param g
 * @param h
 * @param openNodes
 * @param grid
 */
static void AddToOpen(int x, int y, int g, int h, std::vector<std::vector<int>> &openNodes,
                      std::vector<std::vector<State>> &grid)
{
    std::vector<int> node = {x, y, g, h};
    openNodes.push_back(node);
    grid[x][y] = State::kClosed;
}
/**
 * @brief Compare two nodes based on f value (g+h)
 *
 * @param firstNode
 * @param secondNode
 * @return true
 * @return false
 */
static bool Compare(std::vector<int> firstNode, std::vector<int> secondNode)
{
    return ((firstNode[2] + firstNode[3]) > (secondNode[2] + secondNode[3]) ? true : false);
}
/**
 * @brief CellSort the open list based on the f value
 *
 * @param openNodes
 */
static void CellSort(std::vector<std::vector<int>> *openNodes)
{
    std::sort(openNodes->begin(), openNodes->end(), Compare);
}
/**
 * @brief  check if the current cell is valid (empty and it is on the grid)
 *
 * @param x
 * @param y
 * @param grid
 * @return true
 * @return false
 */
static bool CheckValidCell(int x, int y, std::vector<std::vector<State>> &grid)
{
    bool ret = true;
    if (x < 0 || y < 0)
    {
        ret = false;
    }
    else if (x >= grid.size() || y >= grid[0].size())
    {
        ret = false;
    }
    else if (grid[x][y] != State::kEmpty)
    {
        ret = false;
    }
    else
    {
    }
    return ret;
}
/**
 * @brief ExpandNeighbors to get the valid Neighbors of the current Node
 *
 * @param currentNode
 * @param end
 * @param openNodes
 * @param grid
 */
static void ExpandNeighbors(std::vector<int> currentNode, int end[2], std::vector<std::vector<int>> &openNodes,
                            std::vector<std::vector<State>> &grid)
{

    // Get current node's data.
    int x = currentNode[0];
    int y = currentNode[1];
    int g = currentNode[2];
    const int delta[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    // Loop through current node's potential neighbors.
    for (int loopcounter = 0; loopcounter < 4; ++loopcounter)
    {
        int x_neighbor = x + delta[loopcounter][0];
        int y_neighbor = y + delta[loopcounter][1];

        // Check that the potential neighbor's x2 and y2 values are on the grid and not closed.
        if (CheckValidCell(x_neighbor, y_neighbor, grid))
        {
            // Increment g value, compute h value, and add neighbor to open list.
            int g_neighbor = g + 1;
            int h_neighbor = Heuristic(x_neighbor, y_neighbor, end[0], end[1]);
            openNodes.push_back({x_neighbor, y_neighbor, g_neighbor, h_neighbor});
        }
    }
}