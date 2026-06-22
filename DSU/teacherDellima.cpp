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

  unordered_map<int, long long> mp;

  for (int i = 1; i <= n; i++)
  {
    mp[dsu.find(i)]++;
  }

  long long ans = 1;
  const long long MOD = 1000000007;

  for (auto &it : mp)
  {
    ans = (ans * it.second) % MOD;
  }

  cout << ans << "\n";
}