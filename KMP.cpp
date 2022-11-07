pair<vector<ll>,ll> kmp(string haystack,string needle){
    ll prevLPS = 0;
    pair<vector<ll>,ll>ans;
    vector<ll>lps(needle.size(),0);
    ll i=1;
    ll n = needle.size();
    while(i < n){
        if(needle[i] == needle[prevLPS]){
            lps[i] = prevLPS+1;
            prevLPS++;
            i++;
        }
        else if(prevLPS == 0){
            lps[i]=0;
            i++;
        }
        else{
            prevLPS = lps[prevLPS-1];
        }
    }
    // lps is made from needle
    ans.first = lps;
    ll n_h = haystack.size();
    i = 0; // haystack pointer
    ll j = 0; // needle pointer
    while(i<n_h){
        if(haystack[i]==needle[j]){
            i++;
            j++;
        }
        else{
            if(j==0){
                i++;
            }
            else{
                j=lps[j-1];
            }
        }
        if(j==n){
            ans.second =  (i-j);
            break;
        }
    }
    return ans;
}
