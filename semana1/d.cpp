#include<bits/stdc++.h>
using namespace std;

int main(){
    int testes;
    cin >> testes;

    for(int i = 0; i < testes; ++i){
        int numCamisetas;
        cin >> numCamisetas;
        if(numCamisetas == 1) cout << 1 << '\n';
        else if(numCamisetas == 2) cout << -1 << '\n';
        else{
            cout << 1 << ' ' << 2 << ' ' << 3 << ' ';
            numCamisetas -= 3;
            long long somaAtual = 6;
            while(numCamisetas > 0){
                cout << somaAtual << ' ';
                somaAtual *= 2;
                numCamisetas--;
            }
            cout << '\n';
        }
    }
}