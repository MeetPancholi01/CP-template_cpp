vector<ll>size(1e5+10,0);
vector<ll>parent(1e5+10,-1);

void make(ll v){
    parent[v] = v;
    size[v] = 1;
}

ll find(ll v){
    if(parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

void Union(ll a, ll b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(size[a] < size[b]){
            swap(a,b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}
