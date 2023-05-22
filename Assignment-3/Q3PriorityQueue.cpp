// Done in 35 minutes

#include <iostream>
#include <vector>
#include <utility>


class PriorityQueue
{
private:
    // for index i: left child = 2*i + 1, right child = 2*i + 2, parent = floor of (i-1)/2
    std::vector<std::pair<std::string, int>> arr = {};

public:
    std::vector<std::pair<std::string, int>> getArr()
    {
        return arr;
    }

    std::pair<std::string, int> top(); // gets max element
    void insert(std::string data, int weight);
    void remove(); // removes max element
};

// Runtime: O(logn)
// Space: O(1)
void PriorityQueue::remove()
{
    arr[0] = arr[arr.size() - 1];
    arr.resize(arr.size() - 1);

    int pos = 0;
    int leftChild = 0;
    int rightChild = 0;
    int biggest = 0;

    while ((2 * pos + 1) < arr.size() - 1)
    {

        leftChild = 2 * pos + 1;
        rightChild = pos;

        if ((2 * pos + 2) < arr.size() - 1)
        {
            rightChild = 2 * pos + 2;
        }

        biggest = std::max(arr[rightChild].second, arr[leftChild].second);

        if (biggest > arr[pos].second && biggest == arr[rightChild].second)
        {
            std::pair<std::string, int> temp = arr[rightChild]; 

            arr[rightChild] = arr[pos];
            arr[pos] = temp;
            pos = rightChild;
        }

        else if (biggest > arr[pos].second && biggest == arr[leftChild].second)
        {
            std::pair<std::string, int> temp = arr[leftChild];

            arr[leftChild] = arr[pos];
            arr[pos] = temp;
            pos = leftChild;
        }

        else
            return;
    }
}

// Runtime: O(1)
// Space: O(1)
std::pair<std::string, int> PriorityQueue::top()
{
    return arr[0];
}

// Runtime: O(logn)
// Space: O(1)
void PriorityQueue::insert(std::string data, int weight)
{

    std::pair<std::string, int> x = {data, weight};

    arr.push_back(x);
    int pos = arr.size() - 1;

    while (pos > 0 && arr[pos].second > arr[(pos - 1) / 2].second)
    {
        arr[pos] = arr[(pos - 1) / 2];
        arr[(pos - 1) / 2] = x;

        pos = (pos - 1) / 2;
    }
}

int main()
{

    PriorityQueue pqObject;

    // TEST1: testing the insertation functionality after inputing multiple varying integer/string pairs
    pqObject.insert("a", 10);
    pqObject.insert("b", 9);
    pqObject.insert("c", 3);
    pqObject.insert("d", 0);
    pqObject.insert("e", 4);
    pqObject.insert("f", 26);
    pqObject.insert("g", 5);

    std::vector<std::pair<std::string, int>> arr = pqObject.getArr();

    std::cout << "Changing the following pair array into a max PQ: (a, 10), (b, 9), (c, 3), (d, 0), (e, 4), (f, 26), (g, 5)\nMax PQ: ";
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout <<"("<<arr[i].first<<", "<<arr[i].second<<")";

        if (i != arr.size() - 1)
        {
            std::cout << ", ";
        }
    }

    // TEST2: testing the top() functionality that returns a valid pair with highest weight.
    std::cout << "\n\nRemoving the top value: (" << pqObject.top().first<<", "<<pqObject.top().second<< ")\n";

    // TEST3: testing the remove() functionality that should heapify correctly the last arr element from the top down depending on weight.
    pqObject.remove();
    arr = pqObject.getArr();

    std::cout << "The max PQ now looks like: ";
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout <<"("<<arr[i].first<<", "<<arr[i].second<<")";

        if (i != arr.size() - 1)
        {
            std::cout << ", ";
        }
    }
}