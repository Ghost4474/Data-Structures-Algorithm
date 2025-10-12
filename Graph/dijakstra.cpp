#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
//number of nodes
int V;
//d stores the current shortest path from s to point i, infinity at first
vector<int> d(V, INT_MAX), visited(V, 0);
//adjacency list, store (node, length) connected to each vertex
map<int, vector<pair<int, int> > > adj;
void dij(int s){
  //d is infinity expect for the start point
  d[s] = 0;
  //store min to max, pair(dist, node) store shortest unvisited node
  priority_queue<pair<int, int>, greater<vector<int>>> Q;
  Q.push(make_pair(0, s));
  while(Q.size()){
    pair<int, int> tmp = Q.top();//current shortest d unvisited node
    Q.pop();
    int node = tmp.second, dist = tmp.first;
    //if d[node] has been updated since this pair, this is the version not updated
    //depend on specicf problem
    //and this distance stored, which is dist, will be less than the shortest route, d[node]
    if (dist != d[node] || visited[node]) continue;
    visited[node] = true;
    int connect = adj[node].size();
    for(int i = 0; i < connect; i++){//all nodes connected to it
      int v = adj[node][i].first, l = adj[node][i].second;
      if(d[v] > dist + l){
        d[v] = dist + l;
        Q.push(make_pair(d[v], v));//insert if distance improved
      }
    }
  }//all vertices done
}
int main(){
  // Initialize the graph
  V = 5; // Example: 5 nodes
  d.resize(V, INT_MAX);
  visited.resize(V, 0);
  // Add edges (example)
  adj[0].push_back(make_pair(1, 10));
  adj[0].push_back(make_pair(2, 5));
  adj[1].push_back(make_pair(2, 2));
  adj[1].push_back(make_pair(3, 1));
  adj[2].push_back(make_pair(1, 3));
  adj[2].push_back(make_pair(3, 9));
  adj[2].push_back(make_pair(4, 2));
  adj[3].push_back(make_pair(4, 4));
  dij(0);
  // Output the shortest distances
  for(int i = 0; i < V; i++){
    cout << "Shortest distance from 0 to " << i << " is " << d[i] << endl;
  }
  return 0;
}