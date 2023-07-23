/*
n is number of avaliable pets
k is number of pet requests

Time spent:       35 minutes
Technique:        Hashmaps and PQ
Time complexity:  O(n+k)
Space complexity: O(n+k)
*/

#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

struct pet
{

    string name = "";
    string type = "";
    int days = 0;

    bool operator<(const pet &rhs) const
    {
        return days < rhs.days;
    }
};

vector<pet> adoptApet(vector<pet> &pets, vector<string> &requests)
{

    map<string, priority_queue<pet>> avaliable;
    vector<pet> output;

    for (int i = 0; i < pets.size(); i++)
    {

        avaliable[pets[i].type].push(pets[i]);
    }

    for (int i = 0; i < requests.size(); i++)
    {

        if (!avaliable[requests[i]].empty())
        {

            pet p = avaliable[requests[i]].top();
            avaliable[requests[i]].pop();
            output.push_back(p);
        }

        else
        {
            for (auto &type : avaliable)
            {
                if (!(type.second).empty())
                {
                    pet p = (type.second).top();
                    (type.second).pop();
                    output.push_back(p);
                    break;
                }
            }
        }
    }

    return output;
}

int main()
{

    vector<pet> pets = {{"Sadie", "dog", 4},
                        {"Woof", "cat", 7},
                        {"Chirpy", "dog", 2},
                        {"Lola", "dog", 1},
                        {"Floofy", "cat", 0}};

    vector<string> requests = {"dog", "cat", "cat", "cat"};

    vector<pet> output = adoptApet(pets, requests);
    cout << "Output is: ";

    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i].name << " ";
    }
}