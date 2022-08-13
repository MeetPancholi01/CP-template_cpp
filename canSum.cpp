ll dp[200005][101];
bool canSum(vector<ll>&arr,ll ind,ll n,ll target,ll avoid){
    if(target == 0){
        return true;
    }
    if(target < 0){
        return false;
    }
    if(ind == n){
        return false;
    }
    if(dp[target][ind] != -1){
        if(dp[target][ind] == 1) return true;
        return false;
    }
    if(ind != avoid){
        dp[target][ind] = (canSum(arr,ind+1,n,target-arr[ind],avoid) || canSum(arr,ind+1,n,target,avoid))?1:0;
    }
    else{
        dp[target][ind] = canSum(arr,ind+1,n,target,avoid);
    }
    if(dp[target][ind] == 1) return true;
    return false;
}
