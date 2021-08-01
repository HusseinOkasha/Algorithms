#include "bits/stdc++.h";
using namespace std;

// time complexity nearly O(1).
class DSU{
public:
    int nNodes, nCmp; // number of components.
    vector<int>parent;
    vector<int>sz;// size of the component that the ith node belongs to.
    DSU(){
        this->nNodes = 0;
        parent = vector<int>();
        sz = vector<int>();
        nCmp = 0;
    }
    void init(int nNodes){
        this->parent = vector<int>(nNodes);
        this->sz = vector<int>(nNodes);
        fill(sz.begin(), sz.end(), 1);
        for (int i=0; i< nNodes; i++){
            parent[i] = i; // at start everyone  is the parent of himself.
        }
        nCmp = nNodes;
    }
    int find_parent(int v){
        if (v == parent[v]){
            return v;
        }
        return parent[v] = find_parent(parent[v]);
    }
    bool join(int a, int b){
        a = find_parent(a);
        b = find_parent(b);
        if (a==b){
            return 0; // they are already in the same set.
        }
        if (sz[a] > sz[b]){
            swap(a,b); // to make sure that a is the smaller.
        }
        parent[a] = b;
        sz[b] += sz[a];
        nCmp--; // decrease number of components because we have joined them.
        return 1;
    }
};
int main(){
   
}