//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
int delRow[] = {-1, 0, 1, 0};
int delCol[] = {0, 1, 0, -1};
class Solution
{
  void dfs(int n, int m, int r, int c, vector<vector<int>> &grid, vector<vector<int>> &vis)
  {
    vis[r][c] = 1;
    for (int i = 0; i < 4; i++)
    {
      int nR = r + delRow[i];
      int nC = c + delCol[i];
      if (nR >= 0 && nR < n && nC >= 0 && nC < m && !vis[nR][nC] && grid[nR][nC] == 1)
      {
        dfs(n, m, nR, nC, grid, vis);
      }
    }
  }

public:
  int numberOfEnclaves(vector<vector<int>> &grid)
  {
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int j = 0; j < m; j++)
    {
      if (!vis[0][j] && grid[0][j] == 1)
      {
        dfs(n, m, 0, j, grid, vis);
      }

      if (!vis[n - 1][j] && grid[n - 1][j] == 1)
      {
        dfs(n, m, n - 1, j, grid, vis);
      }
    }

    for (int i = 0; i < n; i++)
    {
      if (!vis[i][0] && grid[i][0] == 1)
      {
        dfs(n, m, i, 0, grid, vis);
      }

      if (!vis[i][m - 1] && grid[i][m - 1] == 1)
      {
        dfs(n, m, i, m - 1, grid, vis);
      }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == 1 && vis[i][j] == 0)
        {
          ans++;
        }
      }
    }

    return ans;
  }
};

//{ Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> grid[i][j];
      }
    }
    Solution obj;
    cout << obj.numberOfEnclaves(grid) << endl;
  }
}
// } Driver Code Ends