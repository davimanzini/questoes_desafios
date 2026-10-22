#include<bits/stdc++.h>
using namespace std;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<bool> ehPrimo(n + 1, true);
    ehPrimo[0] = ehPrimo[1] = false;

    //crivo de erastostenes
    for(int i = 2; i * i <= n; ++i){
        if(ehPrimo[i]){
            for(int j = i * i; j <= n; j += i){
                ehPrimo[j] = false;
            }
        }
    }

    int numPares = 0;
    for(int i = 2; i <= n / 2; ++i){
        if(ehPrimo[i]){
            int complemento = n - i;
            if(ehPrimo[complemento]) numPares++;
        }
    }

    cout << numPares << '\n';
}