// prefix hash
pair<vector<ll>,vector<ll>> hashit(string &s){
    ll n=s.size();
    vector<ll>pref(n);
    ll p = 31ll;
    vector<ll>pw(n);
    ll mod = 1e9+7;
    ll curr_pow = 1;
    for(int i=0;i<n;i++){
        pw[i] = curr_pow;
        if(i == 0){
            pref[i] = s[i]-'a'+1;
        }
        else{
            pref[i] = pref[i-1] + ((s[i]-'a'+1)*(curr_pow))%mod;
        }
        curr_pow = (curr_pow*p)%mod;
    }
    pair<vector<ll>,vector<ll>>ans;
    ans.first = pref;
    ans.second = pw;
    return ans;
}

// s is a pattern && t is a text here
vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

    vector<int> occurences;
    for (int i = 0; i + S - 1 < T; i++) { 
        long long cur_h = (h[i+S] + m - h[i]) % m; 
        if (cur_h == h_s * p_pow[i] % m)
            occurences.push_back(i);
    }
    return occurences;
}
