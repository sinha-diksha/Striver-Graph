#include <bits/stdc++.h>
using namespace std;

bool bfs(int src, int V, vector<int> adj[], vector<int> &visited)
{
  visited[src] = 1;
  queue<pair<int, int>> q;
  q.push({src, -1});
  while (!q.empty())
  {
    int node = q.front().first;
    int parent = q.front().second;
    q.pop();
    for (auto adjNode : adj[node])
    {
      if (!visited[adjNode])
      {
        visited[adjNode] = 1;
        q.push({adjNode, node});
      }
      else
      {
        if (parent != adjNode)
        {
          return true;
        }
      }
    }
  }
  return false;
}

bool isCycle(int V, vector<int> adj[])
{
  vector<int> visited(V);
  for (int i = 0; i < V; i++)
  {
    if (!visited[i])
    {
      if (bfs(i, V, adj, visited))
      {
        return true;
      }
    }
  }
  return false;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int V;
    cin >> V;
    int E;
    cin >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    cout << isCycle(V, adj) << endl;
  }
}