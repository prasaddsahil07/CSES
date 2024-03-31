#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int a, b;
    cin>>a>>b;
    ll xVal = (2*a-b);
    ll yVal = (2*b-a);
    if(xVal%3 || xVal <0 || yVal%3 || yVal<0)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}