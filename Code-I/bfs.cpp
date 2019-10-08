// BFS ON A GRAPH
//REG NO. - 17BCS28
#include <bits/stdc++.h>
using namespace std;

void createAndAddEdge(vector <int> adjList[], int u, int v){
  adjList[u].push_back(v);
  adjList[v].push_back(u);
}

void BFS(vector <int> adjList[], vector <bool> visitedVertex, int source){
  queue <int> Q;
  int v;
  Q.push(source);
  while (!Q.empty()){
    v = Q.front();
    visitedVertex.at(v) = true;
    Q.pop();
    cout << v << " "; // Print Vertex
    for (vector<int>::iterator it = adjList[v].begin(); it != adjList[v].end(); it++)
      if (!visitedVertex.at(*it)){
        Q.push(*it);
        visitedVertex.at(*it) = true;
      }
  }
  cout << endl;
}

int main (void){
  const int numVertices = 7;
  int source = 0;
  vector<int> adjList[numVertices];
  vector <bool> visitedVertex(numVertices, false);
  createAndAddEdge(adjList, 0, 1);
  createAndAddEdge(adjList, 0, 2);
  createAndAddEdge(adjList, 1, 4);
  createAndAddEdge(adjList, 1, 3);
  createAndAddEdge(adjList, 4, 3);
  createAndAddEdge(adjList, 4, 6);
  createAndAddEdge(adjList, 3, 5);

  BFS(adjList, visitedVertex, source);
}
