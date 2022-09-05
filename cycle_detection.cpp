// FOR UNDIRECTED GRAPH
vector<bool>vis(1e5,false);
vector<int>ans;
bool detect(int node,int prev,vector<vector<int>>&adj){
    vis[node]=true;
    ans.pb(node);
    for(auto it:adj[node]){
        if(!vis[it]){
            if(detect(it,node,adj)){
                return true;
            }
        }
        else{
            if(it != prev){
                ans.pb(it);
                return true;
            }
        }
        // ans.pop_back();
    }
    ans.pop_back();
    return false;
}
// FOR DIRECTED GRAPH
vector<bool>vis(1e5,false);
vector<int>ans;
bool detect(int node,int prev,vector<vector<int>>&adj){
    vis[node]=true;
    ans.pb(node);
    for(auto it:adj[node]){
        if(!vis[it]){
            if(detect(it,node,adj)){
                return true;
            }
        }
        else{
            if(it != prev){
                ans.pb(it);
                return true;
            }
        }
        // ans.pop_back();
    }
    ans.pop_back();
    return false;
}
