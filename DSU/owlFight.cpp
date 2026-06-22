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

    if (rootX > rootY)
    {
      parent[rootY] = rootX;
    }
    else
    {
      parent[rootX] = rootY;
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
    cin >> q1 >> q2;
    int r1 = dsu.find(q1);
    int r2 = dsu.find(q2);

    if (r1 == r2)
    {
      cout << "TIE\n";
    }
    else
    {
      cout << (r1 > r2 ? q1 : q2) << "\n";
    }
  }
}