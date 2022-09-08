ll up[200001][20];
void solve(ll node,ll par,vector<vector<ll>>&adj){
    up[node][0] = par;
    for(int i=1;i<=19;i++){
        if(up[node][i-1] != -1){
            up[node][i] = up[up[node][i-1]][i-1];
        }
        else{
            up[node][i] = -1;
        }
    }
    for(auto child:adj[node]){
        if(child != par){
            solve(child,node,adj);
        }
    }

}

ll query(ll node,ll k){
    if(k == 0 or node == -1){
        return node;
    }
    for(int i=19;i>=0;i--){
        if(k >= (1 << i)){
            return query(up[node][i],k-(1 << i));
        }
    }
}
