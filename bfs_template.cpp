void bfs(){
    ll n,m,u,v;
    int node;
    cin >> n >> m;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        cin >> u >>  v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<bool>vis(n+1,false);
    vector<int>path(n+1,-1);
    queue<int>q;
    q.push(1);
    vis[1] = true;
    while(!q.empty()){
        node = q.front();
        q.pop();
        for(auto it:adj[node]){
            if(!vis[it]){
                path[it] = node;
                vis[it] = true;
                q.push(it);
            }
        }
    }
    if(path[n] == -1){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        vector<int>ans;
        node = n;
        ans.pb(n);
        while(node != 1){
            ans.pb(path[node]);
            node = path[node];
        }
        cout << ans.size() << endl;
        for(int i=ans.size()-1;i>=0;i--){
            cout << ans[i] << " ";
        }
        cout << endl;
    }


}
