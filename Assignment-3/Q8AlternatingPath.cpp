/*
V is number of nodes
E is number of edges

Time spent:       40 minutes
Technique:        BFS
Time complexity:  O(V+E)
Space complexity: O(V)
*/


#include <iostream>
#include <vector>
#include <stack>



struct node{
    std::string value = "";
    bool visited = false;
    bool prevIsRed = false;

    std::vector<node*> edges = {};
    std::vector<bool> edgeIsRed = {};


    node(std::string a){
        value = a;
    }
};



int AlternatingPath(std::vector<node*> nodes, node* start, node* end)
{
    
    std::stack<std::pair<node*, int>> order;

    order.push({start, 0});
 
    while(!order.empty()){

        std::pair<node*, int> cur = order.top();
        order.pop();

        bool edgePrevIsRed = cur.first->prevIsRed;
        cur.first->visited = true;

        if (cur.first == end){
            return cur.second;
        }

        for(int i=0; i<cur.first->edges.size(); i++){

            bool alternateEdges = (edgePrevIsRed^cur.first->edgeIsRed[i]) ||cur.first == start;

            if(!cur.first->edges[i]->visited && alternateEdges){
                
                cur.first->edges[i]->prevIsRed = cur.first->edgeIsRed[i];
                order.push({cur.first->edges[i],cur.second+1});
            }

        }

    }

    return -1;
   
}



int main()
{   


    //TEST 1: testing with a medium sized graph, containing cycles and a valid path between start and end
    node A("A");
    node B("B");
    node C("C");
    node D("D");
    node E("E");
    std::vector<node*> nodes = {&A, &B, &C, &D, &E};

    A.edges = {&B, &C, &D}; 
    A.edgeIsRed = {false, true, true};

    B.edges = {&D, &E};
    B.edgeIsRed = {false, false};

    C.edges = {&B};
    C.edgeIsRed = {true};

    D.edges = {&C, &E};
    D.edgeIsRed = {false, true};

    E.edges = {&C};
    E.edgeIsRed = {true};
    
    std::cout<<"Testing with graph #1 from A to E: "<<AlternatingPath(nodes, &A, &E)<<"\n";

    //TEST 2: Same graph as test 1, but testing two nodes with no valid path between them
    std::cout<<"Testing with graph #1 from A to E: "<<AlternatingPath(nodes, &E, &D)<<"\n";

}