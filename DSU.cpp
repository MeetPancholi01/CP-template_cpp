vector<ll>siz(1e5+10,0);
vector<ll>parent(1e5+10,-1);

void make(ll v){
    parent[v] = v;
    siz[v] = 1;
}

ll find(ll v){
    if(parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

void Union(ll a, ll b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(siz[a] < siz[b]){
            swap(a,b);
        }
        parent[b] = a;
        siz[a] += siz[b];
    }
}
