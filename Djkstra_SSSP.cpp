ll inf = 1ll*1e18;

int main(){
    init_code();
    //code here
    ll n,m,u,v,w;
    cin >> n >> m;
    vector<vector<pair<ll,ll>>>adj(n+1);
    vector<ll>dis(n+1,inf);
    dis[1] = 0;
    for(int i=0;i<m;i++){
        cin >> u >> v >> w;
        adj[u].pb({v,w});
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    pq.push({0,1});
    while(!pq.empty()){
        ll node = pq.top().second;
        ll ds = 1ll*pq.top().first;
        pq.pop();
        if(dis[node] < ds) continue;
        for(auto it:adj[node]){
            if(dis[it.first] > 1ll*it.second + 1ll*ds){
                dis[it.first] = 1ll*it.second+1ll*ds;
                pq.push({dis[it.first],it.first});
            }
        }
    }
}
