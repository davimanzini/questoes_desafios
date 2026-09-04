#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    long long numVisuais, numCategorias;
    cin >> numVisuais >> numCategorias;

    double raiz = pow(numVisuais, 1.0 / numCategorias);
    long long raizInt = floor(raiz);

    long long currProd = 1;
    for (long long i = 0; i < numCategorias; i++) {
        currProd *= raizInt;
    }

    long long next = raizInt + 1;
    long long ans = raizInt * numCategorias;

    while(currProd < numVisuais){
        currProd /= raizInt;
        currProd *= next;
        ans++;
    }
    cout << ans << "\n";
}