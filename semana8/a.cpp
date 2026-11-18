#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int numPartes;
    cin >> numPartes;

    long long numDivisores = 1;

    for(int i = 0; i < numPartes; ++i){

        int primo, potencia;
        cin >> primo >> potencia;

        numDivisores *= (potencia + 1) % MOD;


    }
}