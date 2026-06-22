#include <iostream>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
  vector<int> parent;
  vector<int> rank;

public:
  DSU(int n)
  {
    parent.resize(n);
    rank.resize(n, 0);

    for (int i = 0; i < n; i++)
    {
      parent[i] = i;
    }
  }

  int find(int x)
  {
    if (parent[x] != x)
    {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  void unionByRank(int x, int y)
  {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY)
      return;

    if (rank[rootX] < rank[rootY])
    {
      parent[rootX] = rootY;
    }
    else if (rank[rootX] > rank[rootY])
    {
      parent[rootY] = rootX;
    }
    else
    {
      parent[rootX] = rootY;
      rank[rootY]++;
    }
  }
};
int main()
{
  int n, m;
  cin >> n >> m;

  DSU dsu(n + 1);

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    dsu.unionByRank(u, v);
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++)
  {
    int q1, q2;
    if (dsu.find(q1) == dsu.find(q2))
    {
      cout << "TLE" << endl;
    }
    else
    {
      int ans = q1 > q2 ? q1 : q2;
      cout << ans << endl;
    }
  }
}