vector<bool>vis(1e5+10,false);

void dfs(int vertex){
    // take action on vertex after entering the vertex
    vis[vertex] = true;
    for(auto child:adj[vertex]){
        if(vis[child]) continue;
        // take action on child before entering the child
        dfs(child);
        // take action on the child after exiting the child
    }
    // take action on the vertex before exiting the vertex
}
