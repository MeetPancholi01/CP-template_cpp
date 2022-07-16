#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
vector<ll> prime_divisors(ll n){
    vector<ll>arr(1000001);
    for(ll i=0;i<1000001;i++){
        arr[i] = i;
    }
    for(ll i = 2;i*i <= n;i++){
        if(arr[i] == i){
            for(ll j = i*i;j<=n;j += i){
                if(arr[j]==j){
                    arr[j]=i;
                }
            }
        }
    }
    set<ll>st;
    vector<ll>ans;
    while(n>1){
        st.insert(arr[n]);
        n /= arr[n];
    }
    for(auto it = st.begin();it != st.end();it++){
        ans.pb(*it);
    }
    return ans;

}
vector<ll> all_primes(ll n){
        vector<ll>arr(n+1,true);
        for(ll i=2;i*i<=n;i++){
            if(arr[i]){
                for(ll j=i*i;j<=n;j+=i){
                    if(arr[j]){
                        arr[j]=false;
                    }
                }
            }
        }
        vector<ll>ans;
        for(ll i=2;i<=n;i++){
            if(arr[i] == true){
                ans.pb(i);
            }
        }
        return ans;
}

vector<ll> primes_in_range(ll l,ll r){
    ll lim = sqrt(r);
    vector<ll> primes = all_primes(lim);
    vector<bool>dummy(r-l+1,true);
    vector<ll>res;
    for(auto i:primes){
        ll firstMultiple = (l/i)*i;
        if(firstMultiple < l) firstMultiple += i;
        for(ll j=max(i*i,firstMultiple);j<=r;j+=i){
            dummy[j-l] = false;
        }  
    }
    for(int i=l;i<=r;i++){
        if(dummy[i-l]){
            res.pb(i);
        }
    }
    return res;
}
