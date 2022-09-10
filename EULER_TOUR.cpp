// TYPE 2
void euler_tour(ll node,ll par,vector<ll>&arr,vector<ll>&val,vector<ll>&start,vector<ll>&end,ll &timer,vector<vector<ll>>&adj){
    arr.pb(val[node]);
    start[node] = timer;
    timer++;
    for(auto it:adj[node]){
        if(it != par){
            euler_tour(it,node,arr,val,start,end,timer,adj);
        }
    }
    end[node] = timer;
    arr.pb(val[node]);
    timer++;
}
