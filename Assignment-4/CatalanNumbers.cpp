/*
Time spent:       25 minutes
Technique:        DP using arr of size 2n
Time complexity:  O(n) 
Space complexity: O(n)
*/


#include <iostream>
#include <vector>

using namespace std;

vector<double> calcCatalan(int c)
{

    vector<double> arr(2 * c + 1, 0); // nth index is nth factorial
    vector<double> ans(c + 1, 0);

    arr[0] = 1;

    for (int i = 1; i < 2 * c + 1; i++)
    {

        arr[i] = arr[i - 1] * i;
    }

    for (int i = 0; i < c + 1; i++)
    {
        ans[i] = arr[2 * i] / (arr[i] * arr[i + 1]);
    }

    return ans;
}

int main()
{

    vector<double> out = calcCatalan(10);

    // Print the Catalan numbers from 0 to 10
    cout << "Catalan numbers from 0 to 10"<< ":" << endl;
    for (int i = 0; i < 10; ++i)
    {
        cout << out[i] << " ";
    }
    cout << endl;
}