/*
V is number of cities
E is number of roads

Time spent:       40 minutes
Technique:        Hashmap to build adjacency set, then did DFS
Time complexity:  O(E+V)
Space complexity: O(E+V)
*/

#include <iostream>
#include <vector>
#include <map>

std::map<std::string, std::vector<std::string>> adjacencySet(std::vector<std::pair<std::string, std::string>> &edges)
{

    std::map<std::string, std::vector<std::string>> adjacencyMap;

    for (int i = 0; i < edges.size(); i++)
    {

        adjacencyMap[edges[i].first].push_back(edges[i].second);
        adjacencyMap[edges[i].second].push_back(edges[i].first);
    }

    return adjacencyMap;
}

void dfs(int cityIndex, std::map<std::string, int> &cityToIndex, std::map<std::string, std::vector<std::string>> &adjacency, std::vector<std::string> &cities)
{

    std::string city = cities[cityIndex];
    cities[cityIndex] = "*";

    for (int i = 0; i < adjacency[city].size(); i++)
    {

        int index = cityToIndex[adjacency[city][i]];
        if (city == "Homer")
        {
        }
        if (cities[index] != "*")
        {

            dfs(index, cityToIndex, adjacency, cities);
        }
    }
}

int roadNetoworks(std::vector<std::string> cities, std::vector<std::pair<std::string, std::string>> roads)
{

    std::map<std::string, std::vector<std::string>> adjacency = adjacencySet(roads);
    std::map<std::string, int> cityToIndex;

    for (int i = 0; i < cities.size(); i++)
    {
        cityToIndex[cities[i]] = i;
    }

    int sum = 0;

    for (int i = 0; i < cities.size(); i++)
    {

        if (cities[i] != "*" && adjacency[cities[i]].size() > 0)
        {

            dfs(i, cityToIndex, adjacency, cities);
            sum++;
        }
    }

    return sum;
}

int main()
{

    // TEST1: Checks if function works for 2 seperate connected graphs and some disconnected nodes
    std::vector<std::string> cities1 = {"Skagway", "Juneau", "Gustavus", "Homer", "Port Alsworth",
                                        "Glacier Bay", "Fairbanks", "McCarthy", "Copper Center", "Healy", "Anchorage"};

    std::vector<std::pair<std::string, std::string>> roads1 = {{"Anchorage", "Homer"}, {"Glacier Bay", "Gustavus"}, {"Copper Center", "McCarthy"}, {"Anchorage", "Copper Center"}, {"Copper Center", "Fairbanks"}, {"Healy", "Fairbanks"}, {"Healy", "Anchorage"}};

    std::cout << "Number of road networks in example 1: " << roadNetoworks(cities1, roads1) << "\n";

    // TEST2: Checks if function works for 3 seperate connected graphs with cycles
    std::vector<std::string> cities2 = {"Kona", "Hilo", "Volcano", "Lahaina", "Hana", "Haiku",
                                        "Kahului", "Princeville", "Lihue", "Waimea"};

    std::vector<std::pair<std::string, std::string>> roads2 = {{"Kona", "Volcano"}, {"Volcano", "Hilo"}, {"Lahaina", "Hana"}, {"Kahului", "Haiku"}, {"Hana", "Haiku"}, {"Kahului", "Lahaina"}, {"Princeville", "Lihue"}, {"Lihue", "Waimea"}};

    std::cout << "Number of road networks in example 2: " << roadNetoworks(cities2, roads2);
}