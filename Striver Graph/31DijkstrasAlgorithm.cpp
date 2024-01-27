/*
Implementing Dijkstra Algorithm
MediumAccuracy: 50.83%Submissions: 136K+Points: 4
30+ People have Claimed their 90% Refunds. Start Your Journey Today!

banner
Given a weighted, undirected and connected graph of V vertices and an adjacency list adj where adj[i] is a list of lists containing two integers where the first integer of each list j denotes there is edge between i and j , second integers corresponds to the weight of that  edge . You are given the source vertex S and You to Find the shortest distance of all the vertex's from the source vertex S. You have to return a list of integers denoting shortest distance between each node and Source vertex S.


Note: The Graph doesn't contain any negative weight cycle.



Example 1:

Input:
V = 2
adj [] = {{{1, 9}}, {{0, 9}}}
S = 0
Output:
0 9
Explanation:

The source vertex is 0. Hence, the shortest
distance of node 0 is 0 and the shortest
distance from node 1 is 9.


Example 2:

Input:
V = 3, E = 3
adj = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}}
S = 2
Output:
4 3 0
Explanation:

For nodes 2 to 0, we can follow the path-
2-1-0. This has a distance of 1+3 = 4,
whereas the path 2-0 has a distance of 6. So,
the Shortest path from 2 to 0 is 4.
The shortest distance from 0 to 1 is 1 .


Your Task:
You don't need to read input or print anything. Your task is to complete the function dijkstra()  which takes the number of vertices V and an adjacency list adj as input parameters and Source vertex S returns a list of integers, where ith integer denotes the shortest distance of the ith node from the Source node. Here adj[i] contains a list of lists containing two integers where the first integer j denotes that there is an edge between i and j and the second integer w denotes that the weight between edge i and j is w.



Expected Time Complexity: O(V2).
Expected Auxiliary Space: O(V2).



Constraints:
1 ≤ V ≤ 1000
0 ≤ adj[i][j] ≤ 1000
1 ≤ adj.size() ≤ [ (V*(V - 1)) / 2 ]
0 ≤ S < V
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> ans(V, INT_MAX);
  ans[S] = 0;
  pq.push({0, S});
  while (!pq.empty())
  {
    int dist = pq.top().first;
    int node = pq.top().second;
    pq.pop();
    for (auto it : adj[node])
    {
      int edgeWeight = it[1];
      int adjNode = it[0];
      if (edgeWeight + dist < ans[adjNode])
      {
        ans[adjNode] = edgeWeight + dist;
        pq.push({ans[adjNode], adjNode});
      }
    }
  }

  return ans;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj[V];
    int i = 0;
    while (i++ < E)
    {
      int u, v, w;
      cin >> u >> v >> w;
      vector<int> t1, t2;
      t1.push_back(v);
      t1.push_back(w);
      adj[u].push_back(t1);
      t2.push_back(u);
      t2.push_back(w);
      adj[v].push_back(t2);
    }
    int S;
    cin >> S;

    vector<int> res = dijkstra(V, adj, S);
    for (int i = 0; i < V; i++)
      cout << res[i] << " ";
    cout << endl;
  }
  return 0;
}