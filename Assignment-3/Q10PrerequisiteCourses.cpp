/*
V is number of courses
E is number of edges (course to prerequiste = edge)

Time spent:       35 minutes
Technique:        Topological sort using DFS
Time complexity:  O(V+E)
Space complexity: O(V)
*/

#include <iostream>
#include <vector>
#include <map>

void dfs(std::map<std::string, bool> &visited, std::map<std::string, std::vector<std::string>> &prereqs, std::string course, std::vector<std::string> &sortedDag)
{

    visited[course] = true;

    for (int i = 0; i < prereqs[course].size(); i++)
    {

        if (!visited.count(prereqs[course][i]))
        {

            dfs(visited, prereqs, prereqs[course][i], sortedDag);
        }
    }

    sortedDag.push_back(course);
}

std::vector<std::string> PrerequisiteCourses(std::vector<std::string> &courses, std::map<std::string, std::vector<std::string>> &prereqs)
{

    std::vector<std::string> sortedDag; // reverse order (first course should have no prereqs)
    std::map<std::string, bool> visited;

    for (int i = 0; i < courses.size(); i++)
    {

        if (!visited.count(courses[i]))
        {

            dfs(visited, prereqs, courses[i], sortedDag);
        }
    }

    return sortedDag;
}

void printArr(std::vector<std::string> arr)
{

    std::cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i];

        if (i != arr.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]\n\n";
}

int main()
{

    // TEST 1: testing a graph with each node having only max 1 edge with total 5 nodes
    std::vector<std::string> courses1 = {"Intro to Programming", "Data Structures", "Advanced Algorithms", "Operating Systems", "Databases"};
    std::map<std::string, std::vector<std::string>> prereqs1 = {{"Data Structures", {"Intro to Programming"}}, {"Advanced Algorithms", {"Data Structures"}}, {"Operating Systems", {"Advanced Algorithms"}}, {"Databases", {"Advanced Algorithms"}}};

    std::cout << "Testing the course ordering for test 1:\n";
    printArr(PrerequisiteCourses(courses1, prereqs1));

    // TEST 2: testing a graph with some nodes having multiple edges
    std::vector<std::string> courses2 = {"Intro to Writing", "Contemporary Literature", "Ancient Literature", "Comparative Literature", "Plays & Screenplays"};
    std::map<std::string, std::vector<std::string>> prereqs2 = {{"Contemporary Literature", {"Intro to Writing"}}, {"Ancient Literature", {"Intro to Writing"}}, {"Comparative Literature", {"Ancient Literature", "Contemporary Literature"}}, {"Plays & Screenplays", {"Intro to Writing"}}};

    std::cout << "Testing the course ordering for test 2:\n";
    printArr(PrerequisiteCourses(courses2, prereqs2));

    return 0;
}