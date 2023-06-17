/*
V is number of vertices
E is number of edges

Time spent:       40 minutes
Technique:        DFS while keeping track of shortest distance in each node
Time complexity:  O(V*E)
Space complexity: O(V*E) including recusrive stack
*/

#include <iostream>
#include <vector>
#include <map>


std::map<std::string, std::vector<std::pair<std::string, double>>> adjacencySet(std::vector<std::pair<std::string, std::string>> edges, std::vector<double> weights)
{

    std::map<std::string, std::vector<std::pair<std::string, double>>> adjacencyMap;

    for (int i = 0; i < edges.size(); i++)
    {

        adjacencyMap[edges[i].first].push_back({edges[i].second, weights[i]});
        adjacencyMap[edges[i].second].push_back({edges[i].first, weights[i]});
    }

    return adjacencyMap;
}

void dfs(std::string node, int k, std::map<std::string, std::vector<std::pair<std::string, double>>>& graph, std::map<std::string, double>& shortestPath){

  for(int i=0; i<graph[node].size(); i++){

        bool option1 = !shortestPath.count(graph[node][i].first) && graph[node][i].second + shortestPath[node] <= k;
        bool option2 = shortestPath.count(graph[node][i].first) && shortestPath[graph[node][i].first] > shortestPath[node] + graph[node][i].second;

        if(option1 || option2){

            shortestPath[graph[node][i].first] = graph[node][i].second + shortestPath[node] + 1;
            dfs(graph[node][i].first, k, graph, shortestPath);
        }
  }

    
}

int VacationDestinations(std::vector<std::pair<std::string, std::string>> edges, std::vector<double> weights, std::string origin, int k)
{
    std::map<std::string, std::vector<std::pair<std::string, double>>> graph = adjacencySet(edges, weights);
    std::map<std::string, double> shortestPath;
    shortestPath[origin] = 0;
    dfs(origin, k, graph, shortestPath);
    

    return shortestPath.size()-1;
    
}


int main()
{
    std::vector<std::pair<std::string, std::string>> edges1 = {{"Boston", "New York"}, {"New York", "Philadelphia"}, {"Boston", "Newport"}, {"Washington, D.C.", "Harper's Ferry"}, {"Boston", "Portland"}, {"Philadelphia", "Washington, D.C."}};
    std::vector<double> weights1 = {4, 2, 1.5, 1, 2.5, 2.5};
    
    //TEST 1: Checking for k=5, should not count some cities due to the 1 hour layover, total 2 cities.
    std::cout<<"Testing the first graph with origin at New York and K = 5: \n";
    std::cout<<"Output: "<<VacationDestinations(edges1, weights1, "New York", 5)<<" different cities\n";

    //TEST 2: Checking for k=7, should count more cities that would be exclucded in k=5 for a total of 4.
    std::cout<<"Testing the first graph with origin at New York and K = 7: \n";
    std::cout<<"Output: "<<VacationDestinations(edges1, weights1, "New York", 7)<<" different cities\n";

    //TEST 3: Checking for k=8, even though 1 more distance, should allow 2 more cities for a total of 6.
    std::cout<<"Testing the first graph with origin at New York and K = 8: \n";
    std::cout<<"Output: "<<VacationDestinations(edges1, weights1, "New York", 8)<<" different cities\n";
    

   
}