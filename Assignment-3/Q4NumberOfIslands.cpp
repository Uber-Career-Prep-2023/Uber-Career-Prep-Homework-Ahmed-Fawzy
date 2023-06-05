/*
n is number of elements in matrix

Time spent:       30 minutes
Technique:        DFS-- treating the matrix as a graph
Time complexity:  O(n)
Space complexity: O(1) although O(n) including the recursive stack
*/

#include <iostream>
#include <vector>

void dfs(int i, int k, std::vector<std::vector<int>> &matrix);

int numberOfIslands(std::vector<std::vector<int>> &matrix)
{

    int totalSum = 0;

    for (int i = 0; i < matrix.size(); i++)
    {

        for (int k = 0; k < matrix[i].size(); k++)
        {

            if (matrix[i][k] == 1)
            {

                totalSum++;
                dfs(i, k, matrix);
            }
        }
    }

    return totalSum;
}

void dfs(int i, int k, std::vector<std::vector<int>> &matrix)
{

    matrix[i][k] = 0;

    if (i != 0 && matrix[i - 1][k] == 1)
    { // up
        dfs(i - 1, k, matrix);
    }

    if (i < matrix.size() - 1 && matrix[i + 1][k] == 1)
    { // down
        dfs(i + 1, k, matrix);
    }

    if (k != 0 && matrix[i][k - 1] == 1)
    { // left
        dfs(i, k - 1, matrix);
    }

    if (k < matrix[i].size() - 1 && matrix[i][k + 1] == 1)
    { // right
        dfs(i, k + 1, matrix);
    }
}

int main()
{

    // test case 1: Testing on a big matrix, that has 3 islands of varying sizes and some 1s being on the edges.
    std::vector<std::vector<int>> test1 = {{1, 0, 1, 1, 1}, {1, 1, 0, 1, 1}, {0, 1, 0, 0, 0}, {0, 0, 0, 1, 0}, {0, 0, 0, 0, 0}};
    std::cout << "Checking number of islands on the following matrix: \n";
    std::cout << "1,0,1,1,1 \n1,1,0,1,1 \n0,1,0,0,0 \n0,0,0,1,0 \n0,0,0,0,0 \n";
    std::cout << "Number of islands: " << numberOfIslands(test1) << "\n\n";

    // test case 2: Testing on a smaller matrix, only 1 island consisting on only 1 node.
    std::vector<std::vector<int>> test2 = {{1, 0, 0}, {0, 0, 0}};
    std::cout << "Checking number of islands on the following matrix: \n";
    std::cout << "1,0,0 \n0,0,0 \n";
    std::cout << "Number of islands: " << numberOfIslands(test2) << "\n";

    return 0;
}