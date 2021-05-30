#include "bits/stdc++.h"
using namespace std;
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
