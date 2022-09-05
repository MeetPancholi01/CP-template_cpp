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
