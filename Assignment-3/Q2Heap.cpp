// Done in 65 minutes

#include <iostream>
#include <vector>

// Min Heap
class Heap
{
private:
    // for index i: left child = 2*i + 1, right child = 2*i + 2, parent = floor of (i-1)/2
    std::vector<int> arr = {};

public:
    std::vector<int> getArr()
    {
        return arr;
    }
    int top(); // gets min element
    void insert(int x);
    void remove(); // removes min element
};

// Runtime: O(logn)
// Space: O(1)
void Heap::remove()
{
    arr[0] = arr[arr.size() - 1];
    arr.resize(arr.size() - 1);

    int pos = 0;
    int leftChild = 0;
    int rightChild = 0;
    int smallest = 0;

    while ((2 * pos + 1) < arr.size() - 1)
    {

        leftChild = 2 * pos + 1;
        rightChild = pos;

        if ((2 * pos + 2) < arr.size() - 1)
        {
            rightChild = 2 * pos + 2;
        }

        smallest = std::min(arr[rightChild], arr[leftChild]);

        if (smallest < arr[pos] && smallest == arr[rightChild])
        {
            arr[rightChild] = arr[pos];
            arr[pos] = smallest;
            pos = rightChild;
        }

        else if (smallest < arr[pos] && smallest == arr[leftChild])
        {
            arr[leftChild] = arr[pos];
            arr[pos] = smallest;
            pos = leftChild;
        }

        else
            return;
    }
}

// Runtime: O(1)
// Space: O(1)
int Heap::top()
{
    return arr[0];
}

// Runtime: O(logn)
// Space: O(1)
void Heap::insert(int x)
{

    arr.push_back(x);
    int pos = arr.size() - 1;

    while (pos > 0 && arr[pos] < arr[(pos - 1) / 2])
    {
        arr[pos] = arr[(pos - 1) / 2];
        arr[(pos - 1) / 2] = x;

        pos = (pos - 1) / 2;
    }
}

int main()
{

    Heap heapObject;

    // TEST1: testing the insertation functionality after inputing multiple varying integers
    heapObject.insert(10);
    heapObject.insert(9);
    heapObject.insert(3);
    heapObject.insert(0);
    heapObject.insert(4);
    heapObject.insert(26);
    heapObject.insert(5);

    std::vector<int> arr = heapObject.getArr();

    std::cout << "Changing the following array into a min-heap: 10, 9, 3, 0, 4, 26, 5\nMin-heap: ";
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i];

        if (i != arr.size() - 1)
        {
            std::cout << ", ";
        }
    }

    // TEST2: testing the top() functionality that returns a valid integer.
    std::cout << "\n\nRemoving the top value: " << heapObject.top() << "\n";

    // TEST3: testing the remove() functionality that should heapify correctly the last arr element from the top.
    heapObject.remove();
    arr = heapObject.getArr();

    std::cout << "The min-heap now looks like: ";
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i];

        if (i != arr.size() - 1)
        {
            std::cout << ", ";
        }
    }
}