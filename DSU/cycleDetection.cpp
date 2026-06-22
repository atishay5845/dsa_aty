class DSU
{
private:
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
class Solution
{
public:
  bool detectCycle(int n, vector<int> adj[])
  {
    // Code here
    DSU dsu(n);
    for (int u = 0; u < n; u++)
    {
      for (int v : adj[u])
      {
        if (u < v)
        { // ek pair ko ek hi bar
          if (dsu.find(u) == dsu.find(v))
          {
            return true;
          }
          dsu.unionByRank(u, v);
        }
      }
    }
    return false;
  }
};