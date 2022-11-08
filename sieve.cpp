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
// SIEVE APPLICATIONS ------------------------------------------------------------------------------------------------------------------------
pair<vector<ll>,vector<ll>> sieve_lphp(ll N){
    vector<bool>isPrime(N,1);
    vector<ll>lp(N,0),hp(N,0);
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i=2;i<N;i++){
        if(isPrime[i]){
            for(int j=2*i;j<N;j+=i){
                isPrime[j] = false;
                hp[j] = i;
                if(lp[j] == 0) lp[j] = i;
            }
        }
    }
    pair<vector<ll>,vector<ll>>ans;
    ans.first = lp;
    ans.second = hp;
    return ans;
}

vector<ll> prime_fact(ll num){
    vector<ll>ans;
    pair<vector<ll>,vector<ll>>lphp = sieve_lphp(num+10);
    vector<ll> hp = lphp.second;
    while(num > 1){
        ll pf = hp[num];
        while(num%pf == 0){
            num /= pf;
            ans.pb(pf);
        }
    }
    return ans;
}

vector<vector<ll>> divisors(ll N){
    vector<vector<ll>>ans(N);
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            ans[j].pb(i);
        }
    }
    return ans;
}
