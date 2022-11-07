vector<ll> z_func(string &s){ // Qurantine engineers tut
    ll n = s.size();
    vector<ll>z(n,0);
    ll l,r;
    l=r=0;
    for(int i=1;i<n;i++){
        if(i > r){
            l=i;
            r=i;
            while(r<n and s[r] == s[r-l]){
                r++;
            }
            r--;
            z[i] = r-l+1;
        }
        else{
            ll j=i-l;
            if(z[j] < r-i+1){
                z[i]=z[j];
            }
            else{
                l=i;
                while(r<n and s[r-l]==s[r]){
                    r++;
                }
                r--;
                z[i] = r-l+1;
            }
        }
    }
    return z;
}
