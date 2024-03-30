#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void display(ll total, ll n){
    vector<ll> vis(n+1, 0);
    ll target = total/2;
    ll l=1, r=1;
    ll sum = 1, cnt = 0;
    while(r<=n){
        if(sum>target){
            sum -= l;
            l++;
        }
        else if(sum == target){
            cnt = r-l+1;
            cout<<cnt<<endl;
            while(l<=r){
                cout<<l<<" ";
                vis[l]++;
                l++;
            }
            break;
        }
        else{
            r++;
            sum += r;
        }
    }
    cout<<endl;
    cout<<(n-cnt)<<endl;
    for(ll i=1; i<=n; i++){
        if(vis[i] == 0){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

int main(){
    ll n;
    cin>>n;
    ll total = n*(n+1)/2;
    if(total%2){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        display(total, n);
    }
    return 0;
}