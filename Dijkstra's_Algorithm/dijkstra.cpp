#include <bits/stdc++.h>
using namespace std;
/*
 * The algorithm is a for finding the minimum distance between point S and T.
 *  This algorithm works only on graphs with non negative weights.
 *  it's time complexity: O((V+E)Logv)
 *
 */
long long distance(vector<vector<int>> &adj, vector<vector<int>> &cost, int s, int t) {

  priority_queue<pair<long long, int>>pq;

  vector<long long >dist(adj.size(), INT64_MIN);
  vector<bool>visited(adj.size(),false);
  dist[s]=0;
  pq.push(make_pair(0,s));
  pair<long long ,int>current;
  long long  new_dist;
  while (!pq.empty()){
      current = pq.top();
      pq.pop();
      visited[current.second]=true;
      for (int i=0; i< adj[current.second].size();i++){
          if(visited[adj[current.second][i]]){
              continue;
          }
          // note negative sign to find the minimum
          new_dist= dist[current.second]+cost[current.second][i]*-1;
          if (new_dist > dist[adj[current.second][i]]){
              dist[adj[current.second][i]]=new_dist;
              pq.push(make_pair(new_dist,adj[current.second][i]));
          }
      }

  }
  if (dist[t]==INT64_MIN){
      return -1;
  }
  return abs(dist[t]);
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);

}
