#include<bits/stdc++.h>

#define ll long long
using namespace std;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll limite;
    ll a;
    ll b;
    cin >> limite >> a >> b;
    ll numTermosA = limite / a;
    ll numTermosB = limite / b;

    ll mmc = lcm(a, b);
    ll numTermosProduto = limite / mmc;

    ll somaTotal = (limite * (limite + 1))/2;
    ll somaA = (numTermosA * (2 * a + (numTermosA - 1) * a)) / 2;
    ll somaB = (numTermosB * (2 * b + (numTermosB - 1) * b)) / 2;
    ll somaProduto = (numTermosProduto * (2 * mmc + (numTermosProduto - 1) * mmc)) / 2;

    ll ans = somaTotal - somaA - somaB + somaProduto;
    cout << ans << '\n';
}