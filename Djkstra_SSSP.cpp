ll inf = 1ll*1e18;
void init_code(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}

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
// MODIFIED DJKSTRA
ll mod = 1e9+7;
ll inf = 1e17;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
    freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //code here
    ll n,m,u,v,w;
    cin >> n >> m;
    vector<vector<pair<ll,ll>>>adj(n+1);
    for(int i=0;i<m;i++){
        cin >> u >> v >> w;
        adj[u].pb({v,w});
    }
    vector<ll>route(n+1,0); // No of routes giving shortest path 
    vector<ll>min_f(n+1,inf); // Min no of nodes encountered in that shortest path
    vector<ll>max_f(n+1,-inf); // Max nodes encountered in that shortest path
    vector<ll>dis(n+1,inf); // The shortest path
    dis[1] = 0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    route[1] = 1;
    min_f[1] = 0;
    max_f[1] = 0;
    pq.push({0,1});
    while(!pq.empty()){
        ll node = pq.top().second;
        ll wt = pq.top().first;
        pq.pop();
        if(wt > dis[node]) continue;
        for(auto it:adj[node]){
            if(dis[it.first] > wt+it.second){
                dis[it.first] = wt+it.second;
                route[it.first] = route[node];
                min_f[it.first] = min_f[node]+1;
                max_f[it.first] = max_f[node]+1;
                pq.push({dis[it.first],it.first});
            }
            else{
                if(dis[it.first] == wt+it.second){
                    route[it.first] = (route[it.first] + route[node])%mod;
                    min_f[it.first] = min(min_f[it.first],min_f[node]+1);
                    max_f[it.first] = max(max_f[it.first],max_f[node]+1);
                }
            }
        }
    }
    cout << dis[n] << " " << route[n] << " " << min_f[n] << " " << max_f[n] << endl;
    return 0;
}
