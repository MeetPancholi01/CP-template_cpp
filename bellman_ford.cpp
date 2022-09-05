const int INF = 1e17;
const int NINF = INF*(-1);
 
struct triplet{
	int first;
	int second;
	int third;
};
int n, m;	
vector<triplet> edges;
vector<int> dist;
void bellman_ford()
{
	for(int i = 1; i < n; ++i)
	{
		for(auto e: edges)
		{
			int u = e.first;
			int v = e.second;
			int d = e.third;
			if(dist[u] == INF) continue;
			dist[v] = min(dist[v], d+dist[u]);
			dist[v] = max(dist[v], NINF);
		}
	} // n relaxations
 
	for(int i = 1; i < n; ++i)
	{
		for(auto e: edges)
		{
			int u = e.first;
			int v = e.second;
			int d = e.third;
			if(dist[u] == INF) continue;
			dist[v] = max(dist[v], NINF);
			if(dist[u]+d < dist[v])
			{
				dist[v] = NINF;
			}
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	dist.resize(n+1);
	edges.resize(m);
	for(int i = 0; i < m; ++i)
	{
		struct triplet inp;
		cin >> inp.first >> inp.second >> inp.third;
		inp.third *= -1; 
		edges[i] = inp;
	}
 
	for(int i = 2; i <= n; ++i)
	{
		dist[i] = INF;
	}
 
	bellman_ford();
	if(dist[n] == NINF)
	{
		cout << -1 << endl;
		return 0;
	} 
	cout << dist[n] * (-1) << endl;
}


// BELLMAN FORD CAPTURING THE NEGATIVE CYCLE --------------------------------------------------------------------------------------------------------------
struct triplet{
    ll a;
    ll b;
    ll c;
};

ll inf = 1e17;

vector<ll>dist;
vector<ll>relaxant;
vector<triplet>adj;
ll x;
void bellman_ford(ll n,ll m){
    for(int i=1;i<=n;i++){
        x = -1;
        for(auto e:adj){
            ll u = e.a;
            ll v = e.b;
            ll w = e.c;
            if(dist[u]+w < dist[v]){
                dist[v]=dist[u]+w;
                relaxant[v] = u;
                x = v;
            }

        }
    }
}



int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
    freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //code here
    ll n,m;
    cin >> n >> m;
    dist.resize(n+1);
    adj.resize(m);
    relaxant.resize(n+1);
    for(int i=1;i<=n;i++){
        dist[i] = inf;
    }
    struct triplet inp;
    for(int i=0;i<m;i++){
        cin >> inp.a >> inp.b>> inp.c;
        adj[i] = inp;
    }
    bellman_ford(n,m);
    if(x == -1){
        cout << "NO" << endl;
    }
    else{
        vector<ll>cycle;
        for(int i=1;i<=n;i++){
            x = relaxant[x];
        }
        for(ll v=x;;v=relaxant[v]){
            cycle.pb(v);
            if(v == x and cycle.size() > 1){
                break;
            }
        }
        reverse(cycle.begin(),cycle.end());
        cout << "YES" << endl;
        for(int i=0;i<cycle.size();i++){
            cout << cycle[i] << " ";
        }
        cout << endl;
    }

    
    return 0;
}
