//   adj:-
//   0->[1,2,3]
//   1->[]
//   2->[4]
//   3->[]
//   4->[]
  
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<bool> vis(V);
    queue<int> q;
    vector<int> bfs;
    vis[0]=true; 
    q.push(0);  // every graph (here) starts from 0
    while(q.size())
    {
        int node=q.front();
        bfs.push_back(node);
        q.pop();
        
        for(int neigh:adj[node])
        {
            if(!vis[neigh])  //current node i.e. neighbour has to be unvisited
            {
                vis[neigh]=true;
                q.push(neigh);
            }
        }
    }
    return bfs;
}
//TC: O(n) (every node is iterated over) + O(2E) (for every node its neighbours are visited and total neighbours i.e total deg=2*edges(for undirected graphs))