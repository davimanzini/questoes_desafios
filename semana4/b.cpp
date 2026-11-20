#include<bits/stdc++.h>
using namespace std;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int dinheiro;
    cin >> dinheiro;

    vector<int> precos(10);
    int menorCusto = 987654321;

    for(int i = 1; i <= 9; ++i){
        
        cin >> precos[i];
        if(precos[i] < menorCusto) menorCusto = precos[i];
    }

    int maxOperacoes = dinheiro / menorCusto;

    string valorAtual = "";
    int i = 9;
    while(i >= 1 && dinheiro > 0){

        int possivelDinheiro = dinheiro - precos[i];
        if (possivelDinheiro >= 0 && possivelDinheiro / menorCusto == maxOperacoes - 1) {
            dinheiro = possivelDinheiro;
            valorAtual += char(i + '0');
            maxOperacoes--;
        } else {
            i--;
        }
    }
    cout << valorAtual << '\n';
}