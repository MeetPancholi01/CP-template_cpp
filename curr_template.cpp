#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(x) begin(x), end(x)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree <ll,null_type,greater_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> oset; //ordered_set
#define pb push_back
ll fastExpo(ll base, ll expo, ll mod){
    ll ans = 1;
    while(expo > 0){
        if(expo%2){
            ans *= base;
            ans %= mod;
        }
        base *= base;
        base %= mod;
        expo /= 2;
    }
    return ans;
}
ll fact(ll n){
    ll ans = 1;
    for(int i=1;i<=n;i++){
        ans = (ans*1ll*i);
    }
    return ans;
}

ll fact_mod(ll n,ll mod){
    ll ans = 1;
    for(int i=1;i<=n;i++){
        ans = (ans*1ll*i)%mod;
    }
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
    freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //code here
    return 0;
}
