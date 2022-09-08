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

// LCA in LOG(N) --------------------------------------------------------------------------------------------------------------------

ll up[200001][20];
void solve(ll node,ll par,vector<vector<ll>>&adj){
    up[node][0] = par;
    for(int i=1;i<=19;i++){
        if(up[node][i-1] != 0){
            up[node][i] = up[up[node][i-1]][i-1];
        }
        else{
            up[node][i] = 0;
        }
    }
    for(auto child:adj[node]){
        if(child != par){
            solve(child,node,adj);
        }
    }
 
}
 
void makeHeights(ll node,ll par,vector<ll>&heights,vector<vector<ll>>&adj){
    heights[node] = heights[par]+1;
    for(auto child:adj[node]){
        if(child != par){
            makeHeights(child,node,heights,adj);
        }
    }
}
 
ll level_up(ll node,ll diff){
    for(int i=19;i>=0;i--){
        if(diff == 0 or node == 0){
            break;
        }
        if(diff >= (1 << i)){
            diff -= (1 << i);
            node = up[node][i];
        }
    }
    return node;
}
 
ll lca(ll u,ll v,vector<ll>&heights){
    if(heights[u] < heights[v]){
        swap(u,v);
    }
    u = level_up(u,heights[u]-heights[v]);
    if(u == v){
        return u; 
    }
    for(int i=19;i>=0;i--){
        if(up[u][i] != up[v][i]){
            u =up[u][i];
            v = up[v][i];
        }
    }
    return level_up(u,1);
}
