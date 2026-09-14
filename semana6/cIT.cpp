#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int numEventos;
    cin >> numEventos;

    int monarcaAtual = 1;
    int nextIdx = 2;
    vector<vector<int>> adjacents(numEventos + 2);
    vector<int> pais(numEventos + 2);
    vector<int> vivo(numEventos + 2, 1);
    vector<int> ultimoTestado(numEventos + 2, 0);

    for(int i = 0; i < numEventos; ++i){
        int tipo, nodo;
        cin >> tipo >> nodo;

        if(tipo == 1){
            adjacents[nodo].push_back(nextIdx);
            pais[nextIdx] = nodo;
            nextIdx++;
        }
        else{
            vivo[nodo] = 0;

            while(vivo[monarcaAtual] == 0){
                if(ultimoTestado[monarcaAtual] < adjacents[monarcaAtual].size()){
                    monarcaAtual = adjacents[monarcaAtual][ultimoTestado[monarcaAtual]];
                }
                else{
                    monarcaAtual = pais[monarcaAtual];
                    ultimoTestado[monarcaAtual]++;
                }
            }
            cout << monarcaAtual << '\n';
        }
    }
    return 0;
}