
#include "bits/stdc++.h"
using namespace std;
class Graph{
public:
    int v, e;
    bool directed;
    vector<vector<int>>from_to;
    vector<int>visited;
    vector<vector<pair<int,int>>>from_to_wt; // pair.first is the cost, pair.second is the destination.
    Graph(int v){
        this->v = v;
        this->from_to_wt = vector<vector<pair<int,int>>>(v);
        e = 0;
    }
    void add_edge(int a, int b, int c){
        this->from_to_wt[a].push_back(make_pair(c,b));
        if (!directed){
            this->from_to_wt[b].push_back(make_pair(c,a));
            e++;
        }
        e++;
    }
    bool detect_cycles(){
        // this function works for directed and undirected graphs.
        this->visited=vector<int>(v, 0);// 0: means not visited , 1: means processing ,2: node and it's descendants are done processing
        int vid=0;
        for(int i=0; i< from_to_wt.size(); i++){
            if (visited[i]!=0){continue;}
            if (dfs(i,-1, vid)){return true;}
        }
        return false;
    }
    bool dfs(int node, int parent, int vid){
        if (visited[node] == 1){
            return true; // contains a cycle;
        }
        else if (visited[node] == 2){
            return false;
        }
        visited[node] = 1;
        for (int i=0 ; i< from_to_wt[node].size(); i++){
            if (from_to_wt[node][i].second == parent && !directed){continue;}
            if (dfs(from_to_wt[node][i].second, node, vid)){
                return true;
            };
        }
        visited[node] = 2;
        return false;
    }


};
int main(){

    return 0;
}