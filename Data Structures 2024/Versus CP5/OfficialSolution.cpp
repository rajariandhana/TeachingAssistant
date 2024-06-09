#include <bits/stdc++.h>
using namespace std;

struct graph{
    int vertexCount, edgeCount;
    vector<vector<pair<int, int> > > adjList;
    
    void init(int v){
        vertexCount = v;
        edgeCount = 0;

        for(int i=0; i<vertexCount; i++){
            vector<pair<int, int> > v;
            adjList.push_back(v); // inserts V ammount of empty vector
        }
    }

    void add_edge(int vertex1, int vertex2, int weight){
        adjList[vertex1].push_back(make_pair(vertex2, weight));
        // adjList[vertex2].push_back(make_pair(vertex1, weight));
        edgeCount++;
    }

    void modifyEdge(int vertex1, int vertex2, int newWeight){
        for (auto& edge : adjList[vertex1]) {
            if (edge.first == vertex2) {
                edge.second = newWeight;
                break;
            }
        }
    }

    int dijkstra(int start, int end){
        vector<bool> visited(vertexCount, false);
        priority_queue <pair<int, int>, 
                        vector <pair<int, int> >, 
                        greater <pair<int, int> > > pq;
        vector<int> result = vector<int>(vertexCount, INT_MAX);
        
        pq.push(make_pair(0, start));
        result[start] = 0;

        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();

            visited[temp.second] = true;

            for(auto vertex:adjList[temp.second]){
                int nextVertex = vertex.first;
                int weight = vertex.second;

                if(!visited[nextVertex]){
                    if(temp.first + weight < result[nextVertex]) {
                        result[nextVertex] = temp.first + weight;
                        pq.push(make_pair(result[nextVertex], nextVertex));
                    }
                }
            }
        }
        return result[end];
    }
};

int main(){
    int vertices, edges;
    cin >> vertices >> edges;
    graph g;
    g.init(vertices);
    for(int i=0; i<edges; i++)
    {
        int vertex1,vertex2,weight;
        cin >> vertex1 >> vertex2 >> weight;
        g.add_edge(vertex1,vertex2,weight);
    }

    int start=0;
    int end=vertices-1;
    
    // cout<<g.dijkstra(start,end)<<endl;
    int shortestDistance = INT_MAX;
    int teleportFrom, teleportTo;
    for(auto& vertex_edges : g.adjList)
    {
        for(auto& edge : vertex_edges)
        {
            int vertex1 = &vertex_edges - &g.adjList[0];
            int vertex2 = edge.first;
            int weight = edge.second;
            g.modifyEdge(vertex1, vertex2,0);
            vector<int> dijkstra_result;
            // cout<<"TELEPORT "<<vertex1<<" "<<vertex2<<" "<<dijkstra_result[end]<<endl;
            shortestDistance = min(shortestDistance, g.dijkstra(start, end));
            g.modifyEdge(vertex1, vertex2,weight);
        }
    }
    cout<<shortestDistance<<endl;
    // cout<<"Shortest distance: "<<shortestDistance<<endl;
    // cout<<"Teleport from "<<teleportFrom<<" to "<<teleportTo<<endl;
    // cout<<"Captain! You can fly from "<<teleportFrom<<" to "<<teleportTo<<endl;


    return 0;
}
/*

6 7
0 3 28
0 4 14
1 3 36
1 5 40
2 5 94
4 1 3
4 2 54
*/