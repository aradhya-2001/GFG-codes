#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> vis;
    vector<int> ans;

    void dfs(int node, vector<int> adj[]) // if we pass adj as reference it will show error
    {
        ans.push_back(node);
        vis[node] = true;

        for (int neigh : adj[node])
        {
            if (!vis[neigh])
            {
                dfs(neigh, adj);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vis.resize(V);
        dfs(0, adj);
        return ans;
    }
};
