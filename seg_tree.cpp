#include <bits/stdc++.h>
using namespace std;
#define ll long long    

class seg_tree{
public:
    vector<int>seg;
    seg_tree(int n){
        seg.resize(4*n+1);
    }
    void build(int ind, int low, int high, int arr[]){
        if(low == high){
            seg[ind] = arr[low];
            return;
        }
        int mid = low + ((high-low)/2);
        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);
        seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
    }

    int query(int ind,int low,int high,int l,int r){
        //no overlap
        //either low > r or high < l
        if(r < low || l > high){
            return INT_MAX;
        }
        //complete overlap
        if(low >= l && high <= r){
            return seg[ind];
        }
        int mid = low + (high-low)/2;
        int left = query(2*ind+1,low,mid,l,r);
        int right = query(2*ind+2,mid+1,high,l,r);
        return min(left,right);

    }

    void update(int ind,int low,int high,int i,int val){
        if(low == high){
            seg[ind]=val;
            return;
        }
        int mid = low + (high-low)/2;
        if(i <= mid){
            update(2*ind+1,low,mid,i,val);
        }
        else{
            update(2*ind+2,mid+1,high,i,val);
        }
        seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
    }
};


// SEG TREE FOR DISTINCT ELEMENTS----------------------------------------------------------------------------
class seg_tree{
public:
    vector<set<char>>seg;
    seg_tree(int n){
        seg.resize(4*n+1);
    }
    void build(int ind, int low, int high, char arr[]){
        if(low == high){
            set<char>st;
            st.insert(arr[low]);
            seg[ind] = st;
            return;
        }
        int mid = low + ((high-low)/2);
        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);
        // seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
        set<char>mod;
        for(auto it:seg[2*ind+1]){
            mod.insert(it);
        }
        for(auto it:seg[2*ind+2]){
            mod.insert(it);
        }
        seg[ind] = mod;
    }

    set<char> query(int ind,int low,int high,int l,int r){
        //no overlap
        //either low > r or high < l
        if(r < low || l > high){
            set<char>emp;
            return emp;
        }
        //complete overlap
        if(low >= l && high <= r){
            return seg[ind];
        }
        int mid = low + (high-low)/2;
        set<char> left = query(2*ind+1,low,mid,l,r);
        set<char> right = query(2*ind+2,mid+1,high,l,r);
        set<char>mod;
        for(auto it:left){
            mod.insert(it);
        }
        for(auto it:right){
            mod.insert(it);
        }
        return mod;
    }

    void update(int ind,int low,int high,int i,char val,char val_er){
        if(low == high){
            seg[ind].erase(val_er);
            seg[ind].insert(val);
            return;
        }
        int mid = low + (high-low)/2;
        if(i <= mid){
            update(2*ind+1,low,mid,i,val,val_er);
        }
        else{
            update(2*ind+2,mid+1,high,i,val,val_er);
        }
        // seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
        set<char>mod;
        for(auto it:seg[2*ind+1]){
            mod.insert(it);
        }
        for(auto it:seg[2*ind+2]){
            mod.insert(it);
        }
        seg[ind] = mod;
    }
};
