class Disjoint
{
public:
  vector<int> parent;
  vector<int> rank;

public:
  Disjoint(int n)
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

  void unionNormal(int x, int y)
  {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY)
    {
      parent[rootY] = rootX;
    }
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
class Solution
{
public:
  int spanningTree(int V, vector<vector<int>> &edges)
  {
    // code here
    sort(edges.begin(), edges.end(), [&](const vector<int> &a, const vector<int> &b)
         { return a[2] < b[2]; });

    Disjoint dsu(V);
    int cnt = 0;
    for (auto it : edges)
    {
      int u = it[0];
      int v = it[1];
      int w = it[2];
      if (dsu.find(u) != dsu.find(v))
      {
        dsu.unionByRank(u, v);
        cnt += w;
      }
    }
    return cnt;
  }
};