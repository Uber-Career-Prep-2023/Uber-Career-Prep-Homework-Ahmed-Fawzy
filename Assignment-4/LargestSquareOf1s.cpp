/*
n is number of elements

Time spent:       30 minutes
Technique:        DP using a 2d vector
Time complexity:  O(n)
Space complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

int largestSquareOf1s(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {

        for (int k = 0; k < matrix[i].size(); k++)
        {

            int up, left, diag = 0;
            if (i != 0 && k != 0 && matrix[i][k] != 0)
            {
                up = matrix[i - 1][k];
                left = matrix[i][k - 1];
                diag = matrix[i - 1][k - 1];
                int res = min(up, min(left, diag));
                if (res != 0)
                {

                    matrix[i][k] = res + 1;
                }
            }
        }
    }

    int max = 1;
    for (int i = 0; i < matrix.size(); i++)
    {

        for (int k = 0; k < matrix[i].size(); k++)
        {
            if (matrix[i][k] > max)
                max = matrix[i][k];
        }
    }

    return max;
}

int main()
{

    vector<vector<int>> matrix1 = {{0, 1, 0, 1},
                                   {0, 0, 1, 1},
                                   {0, 1, 1, 1},
                                   {0, 0, 1, 1}};

    vector<vector<int>> matrix2 = {{0, 1, 0, 1, 1},
                                   {0, 0, 1, 1, 1},
                                   {1, 1, 1, 1, 1},
                                   {1, 1, 1, 1, 1},
                                   {0, 1, 1, 0, 0}};

    int res1 = largestSquareOf1s(matrix1);
    int res2 = largestSquareOf1s(matrix2);
    std::cout << "Output for Test 1: " << res1 << endl;
    std::cout << "Output for Test 2: " << res2 << endl;

    return 0;
}
