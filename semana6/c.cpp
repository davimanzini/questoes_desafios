#include<bits/stdc++.h>
using namespace std;

int recursive(int nodoAtual, vector<vector<int>> &adjacents, vector<int> &pais, vector<int> &vivo, vector<int> &ultimoTestado){
    
    if(vivo[nodoAtual] == 1) return nodoAtual;

    if(ultimoTestado[nodoAtual] < adjacents[nodoAtual].size()){
        int filho = adjacents[nodoAtual][ultimoTestado[nodoAtual]];
        return recursive(filho, adjacents, pais, vivo, ultimoTestado);
    }

    int pai = pais[nodoAtual];
    ultimoTestado[pai]++;

    return recursive(pai, adjacents, pais, vivo, ultimoTestado); 
}

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int numEventos;
    cin >> numEventos;

    int monarcaAtual = 1;
    int nextIdx = 2;
    vector<vector<int>> adjacents(numEventos + 1);
    vector<int> pais(numEventos + 1); //tamanho maior pra grantir
    vector<int> vivo(numEventos + 1, 1); //1 se ta vivo e 0 se ta morto
    vector<int> ultimoTestado(numEventos + 1, 0);

    for(int i = 0; i < numEventos; ++i){
        int tipo, nodo;
        cin >> tipo >> nodo;

        if(tipo == 1){
            adjacents[nodo].push_back(nextIdx);
            pais[nextIdx] = nodo; //marcar o pai do filho lido
            nextIdx++;
        }
        else{ //tipo é 2, morte

            vivo[nodo] = 0;

            if(nodo != monarcaAtual){
                cout << monarcaAtual << '\n';
                continue;
            }
            else{
                int ans = recursive(nodo, adjacents, pais, vivo, ultimoTestado);
                monarcaAtual = ans;
                cout << ans << '\n';
            }
        }
    }
}