#include "bits/stdc++.h"
using namespace std;
/*
time complexity O(v + e).
space complexity O(v).
*/
void dfs(vector<vector<int>> &edges, unordered_map<int, int> &visited, int node, bool &check)
{
	if (visited[node] == 0)
	{
		visited[node] = 1;
		for (int i = 0; i < edges[node].size(); i++)
		{
			dfs(edges, visited, edges[node][i], check);
		}
	}
	else if (visited[node] == 1)
	{
		check = true;
	}
	visited[node] = 2;
}
bool cycleInGraph(vector<vector<int>> edges)
{
	/*
	visited value's meaning:
		0 => means not visited 
		1 => means currently in stack (traversing it's descendants.)
		2 => means it's visited and no longer in stack.  
	*/
	unordered_map<int, int> visited;
	bool check = false;
	int id = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		if (visited[i] == 0)
		{
			dfs(edges, visited, i, check);
			if (check)
			{
				return check;
			}
		}
	}
	return false;
}
