#include<bits/stdc++.h>
using namespace std;
#define ll long long

unordered_map<ll, ll> mp;

ll recursive(ll n){
    if(n == 0) return 1;
    
    if(mp.count(n)) return mp[n];
    
    ll leftFunc = n / 2;
    ll rightFunc = n / 3;
    mp[n] = recursive(leftFunc) + recursive(rightFunc);
    
    return mp[n];
}

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n;
    cin >> n;

    ll ans = recursive(n);
    cout << ans << '\n';
}