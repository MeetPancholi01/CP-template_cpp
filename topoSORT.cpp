vector<bool>vi(1e5+5,false);
void topoSort(ll node,stack<ll>&st,vector<vector<ll>>&adj){
    vi[node] = true;
    for(auto it:adj[node]){
        if(!vi[it]){
            topoSort(it,st,adj);
        }
    }
    st.push(node);
}
stack<ll>st;
for(int i=1;i<=n;i++){
    if(!vi[i]){
        topoSort(i,st,adj);
    }
}
vector<ll>ans;
while(!st.empty()){
    ans.pb(st.top());
    st.pop();
}

// TOPOSORT BY BFS----------------------------------------------------------------
vector<ll> topoSort(ll N,vector<vector<ll>>adj){
    queue<ll>q;
    vector<ll>indeg(N+1,0);
    for(int i=1;i<=N;i++){
        for(auto it:adj[i]){
            indeg[it]++;
        }
    }

    for(int i=1;i<=N;i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    vector<ll>topo;
    while(!q.empty()){
        ll node = q.front();
        q.pop();
        topo.pb(node);
        for(auto it:adj[node]){
            indeg[it]--;
            if(indeg[it] == 0){
                q.push(it);
            }
        }
    }
    return topo;
}
