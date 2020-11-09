#include <bits/stdc++.h>
using namespace std;


/*
  it has time complexity O(n^3).
  it gets the shortest path also when it has edges with
  negative weights.
  One of it's drawbacks is, it doesn't work when there is a cycle
  with edge of negative weight.

  so we used it to solve the problem of detecting negative cycles. 
*/


int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  vector<long long >dist(adj.size(),INT32_MAX);
  bool check= false;
  int new_dist=0;
  dist[0]=0;
  for (int l=0; l<adj.size()+1;l++){
      check=false;
      for (int i=0; i<adj.size();i++){
          for (int j=0; j< adj[i].size();j++){
               if (dist[adj[i][j]] > dist[i]+cost[i][j] ){
                   dist[adj[i][j]]=dist[i]+cost[i][j];
                   if (l==adj.size()){
                       check=true;
                   }
               }
          }
      }
  }

  return check;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
