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

ll MMI(ll n, ll mod)
{
    return fastExpo(n,mod-2,mod);
}


ll nCr(ll n, ll r, ll mod)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    ll fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++){
        fac[i] = (fac[i - 1]*i)%mod;
    }
    return (((fac[n]*MMI(fac[r],mod))%mod)*(MMI(fac[n-r],mod))%mod)%mod;
}

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

vector<vector<ll>> diagonal_elements(vector<vector<ll>>&arr){               // diagonal of the shape ----> / 
    ll r,c;                                        
    ll s_x,s_y,e_x,e_y;
    vector<vector<ll>>diag;
    ll n = arr.size();
    ll m = arr[0].size();
    for(ll tot=1;tot<(n+m);tot++){
        r = min(tot-1,n-1);
        c = min(tot-1,m-1);
        s_x = r;
        e_y = c;
        if(tot-1 > n-1){
            s_y++;
            s_y = min(s_y,m-1);
        }
        else{
            s_y = 0;
        }
        if(tot-1 > m-1){
            e_x++;
            e_x = min(e_x,n-1);
        }
        else{
            e_x = 0;
        }
        // cout << s_x << " " <<  s_y << endl;
        ll start = s_y; 
        vector<ll>dg;
        while(s_x >= 0 and start <= e_y){
            // cout << s_x << " " << s_y << endl;
            dg.pb(arr[s_x][start]);
            s_x--;
            start++;
        }
        diag.pb(dg);
    }
    return diag;
}

void print_arr(ll arr[],ll n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}

void print_arr2(ll *arr,ll r, ll c){  // Call me like this print_arr2((ll*)arr,rows,cols);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout << *(arr+i*c+j) << " ";
        }
        cout << endl;
    }
}

void print_vec2(vector<vector<ll>>&arr){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void print_vec(vector<ll>&arr){
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
}

ll kadane(vector<ll>&arr){
    ll csum = arr[0];
    ll osum = arr[0];
    for(int i=1;i<arr.size();i++){
        if(csum > 0){
            csum += arr[i];
        }
        else{
            csum = arr[i];
        }
        if(csum > osum){
            osum = csum;
        }
    }
    return osum;
}

// max subarray sum of every window size
vector<ll> subsum(vector<ll>&arr){
    ll n = arr.size();
    vector<ll>ans(n+1,INT_MIN);
    for(int i=0;i<n;i++){
        ll temp = 0;
        for(int j=i;j<n;j++){
            temp += arr[j];
            ans[j-i+1] = max(ans[j-i+1],temp);
        }
    }
    return ans;
}

string add(string s1,string s2){
    string res = "";
    int i=s1.size()-1;
    int j = s2.size()-1;
    int carry = 0;
    while(i >= 0 || j >= 0 || carry != 0){
        int ival = (i >= 0)?s1[i]-'0':0;
        int jval = (j >= 0)?s2[j]-'0':0;
        i--;
        j--;
        int sum = ival+jval+carry;
        res.pb(sum%10+'0');
        carry = sum/10;
    }
    reverse(all(res));
    return res;
}

string mult(string s1, string s2){
    int n1 = s1.size();
    int n2 = s2.size();
    vector<int>res(n1+n2,0);
    int i = n2-1;
    int pf = 0;
    while(i >= 0){
        int ival = s2[i]-'0';
        i--;
        int j=n1-1;
        int k = res.size()-1-pf;
        int carry = 0;
        while(j >= 0 || carry != 0){
            int jval = (j>=0)? s1[j]-'0':0;
            j--;
            int prod = ival*jval+carry+res[k];
            res[k] = prod%10;
            carry = prod/10;
            k--;
        }
        pf++;
    }
    string ans = "";
    ll ind = 0;
    for(int i=0;i<res.size();i++){
        if(res[i] != 0){
            ind = i;
            break;
        }
    }
    for(int i=ind;i<res.size();i++){
        ans += to_string(res[i]);
    }
    return ans;
}

void leftRotate_arr(ll arr[],ll n,ll k){     // [1,2,3] -> [2,3,1]
    k%=n;
    reverse(arr,arr+k);
    reverse(arr+k,arr+n);
    reverse(arr,arr+n);
}

void rightRotate_arr(ll arr[],ll n,ll k){        // [1,2,3] -> [3,1,2]
    k%=n;
    reverse(arr,arr+n);
    reverse(arr,arr+k);
    reverse(arr+k,arr+n);
}

void leftRotate_vec(vector<ll>&arr,ll n,ll k){
    k%=n;
    reverse(arr.begin(),arr.begin()+k);
    reverse(arr.begin()+k,arr.end());
    reverse(arr.begin(),arr.end());
}

void rightRotate_vec(vector<ll>&arr,ll n,ll k){
    k%=n;
    reverse(arr.begin(),arr.end());
    reverse(arr.begin(),arr.begin()+k);
    reverse(arr.begin()+k,arr.end());
}

string dtb(ll ln,ll num){
    string ans(32,'0');
    for(int i=0;i<32;i++){
        if((1 << i)&num){
            ans[32-i-1] = '1';
        }
        else{
            ans[32-i-1] = '0';
        }
    }

    return ans.substr(32-ln,ln);

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
