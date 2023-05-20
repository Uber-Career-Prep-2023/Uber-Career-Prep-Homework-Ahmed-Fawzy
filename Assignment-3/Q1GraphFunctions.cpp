// Done in 100 mintues
// Note: V means # of vertices, E means # of edges.

#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stack>

bool bfsHelper(int node, int target, std::map<int, std::vector<int>> &graph, std::map<int, bool> unvisited);
bool dfsHelper(int node, int target, std::map<int, std::vector<int>> &graph, std::map<int, bool> &unvisited);
void topologicalSortDFS(int node, std::map<int, std::vector<int>> &graph, std::stack<int> &stack, std::map<int, bool> &visited);

// Runtime: O(E)
// Space: O(V)
std::map<int, std::vector<int>> adjacencySet(std::vector<std::pair<int, int>> edges)
{

    std::map<int, std::vector<int>> adjacencyMap;

    for (int i = 0; i < edges.size(); i++)
    {

        if (!adjacencyMap.count(edges[i].second))
        {

            adjacencyMap[edges[i].second] = std::vector<int>{};
        }

        adjacencyMap[edges[i].first].push_back(edges[i].second);
    }

    return adjacencyMap;
}

// Runtime: O(V)
// Space: O(V)
bool bfs(int target, std::map<int, std::vector<int>> graph)
{

    std::map<int, bool> unvisited;

    for (auto &val : graph)
    {
        unvisited[val.first] = true;
    }

    for (auto &val : unvisited)
    { // for unconnected components in the graph

        if (val.second)
        {

            if (bfsHelper(val.first, target, graph, unvisited))
            {
                return true;
            }
        }
    }

    return false;
}

bool bfsHelper(int node, int target, std::map<int, std::vector<int>> &graph, std::map<int, bool> unvisited)
{

    std::queue<int> queue;
    queue.push(node);

    while (!queue.empty())
    {

        int node = queue.front();
        queue.pop();

        unvisited[node] = false;

        if (node == target)
        {
            return true;
        }

        for (int i = 0; i < graph[node].size(); i++)
        { // pushes all adjacent nodes

            if (unvisited[graph[node][i]])
            {
                queue.push(graph[node][i]);
            }
        }
    }

    return false;
}

// Runtime: O(V)
// Space: O(V)
bool dfs(int target, std::map<int, std::vector<int>> graph)
{

    std::map<int, bool> unvisited;

    for (auto &val : graph)
    {
        unvisited[val.first] = true;
    }

    for (auto &val : unvisited)
    { // for unconnected components in the graph

        if (val.second)
        {

            if (dfsHelper(val.first, target, graph, unvisited))
            {
                return true;
            }
        }
    }

    return false;
}

bool dfsHelper(int node, int target, std::map<int, std::vector<int>> &graph, std::map<int, bool> &unvisited)
{

    unvisited[node] = false;

    if (target == node)
    {
        return true;
    }

    for (int i = 0; i < graph[node].size(); i++)
    {

        if (unvisited[graph[node][i]] && dfsHelper(graph[node][i], target, graph, unvisited))
        {
            return true;
        }
    }

    return false;
}

// Runtime: O(V)
// Space: O(V)
std::vector<int> topologicalSort(std::map<int, std::vector<int>> graph)
{

    std::stack<int> stack;
    std::map<int, bool> visited;

    for (auto &val : graph)
    {

        if (!visited[val.first])
        {
            topologicalSortDFS(val.first, graph, stack, visited);
        }
    }

    std::vector<int> sorted;

    while (!stack.empty())
    {

        sorted.push_back(stack.top());
        stack.pop();
    }

    return sorted;
}

void topologicalSortDFS(int node, std::map<int, std::vector<int>> &graph, std::stack<int> &stack, std::map<int, bool> &visited)
{
    visited[node] = true;

    for (int i = 0; i < graph[node].size(); i++)
    {

        if (!visited[graph[node][i]])
        {
            topologicalSortDFS(graph[node][i], graph, stack, visited);
        }
    }

    stack.push(node);
}

int main()
{

    // TEST1: testing if adjacencySet works with a cyclic graph and nodes with no outgoing edges.
    std::map<int, std::vector<int>> adjacencyMap = adjacencySet({{1, 2}, {2, 3}, {1, 3}, {3, 2}, {2, 0}});

    std::cout << "Adjaceny Matrix for the set: {1,2}, {2,3}, {1,3}, {3,2}, {2,0} is: \n";
    for (auto &val : adjacencyMap)
    {

        std::cout << val.first << ": ";
        for (auto &ele : val.second)
        {

            std::cout << ele << " ";
        }
        std::cout << "\n";
    }

    // TEST2: testing dfs and bfs for a cyclic graph, with a target node that is reached at different times in each method.
    std::string dfsOut = dfs(3, adjacencyMap) ? "true" : "false";
    std::string bfsOut = bfs(3, adjacencyMap) ? "true" : "false";

    std::cout << "\nRunning DFS on the above graph, is 3 in it ? " << dfsOut;
    std::cout << "\nRunning BFS on the above graph, is 3 in it ? " << bfsOut << "\n\n";

    // TEST3: testing topologicalSort for an adjacencyMap that is a-cyclic and contains no disconnected components.
    std::map<int, std::vector<int>> adjacencyMap2 = adjacencySet({{2, 3}, {3, 1}, {4, 0}, {4, 1}, {5, 0}, {5, 2}});

    std::vector<int> sortedGraph = topologicalSort(adjacencyMap2);
    std::cout << "Running topological sort on the following graph: {2,3}, {3,1}, {4,0}, {4,1}, {5,0}, {5,2} \nresult: ";

    for (int i = 0; i < sortedGraph.size(); i++)
    {
        std::cout << sortedGraph[i];

        if (i != sortedGraph.size() - 1)
        {
            std::cout << ",";
        }
    }
    std::cout << "\n";
}