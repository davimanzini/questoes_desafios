#include<bits/stdc++.h>
using namespace std;

int main(){
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int numFuncionarios, numConsultas;
    cin >> numFuncionarios >> numConsultas;

    vector<vector<int>> up(numFuncionarios + 1, vector<int>(18));
    up[1][0] = 1; //diretor é chefe dele mesmo

    vector<int> nivelFuncionario(numFuncionarios + 1);
    nivelFuncionario[1] = 1;
    
    for(int i = 2; i <= numFuncionarios; ++i){

        int currChefe;
        cin >> currChefe;

        up[i][0] = currChefe;
        nivelFuncionario[i] = nivelFuncionario[currChefe] + 1;
    }
    
    for(int j = 1; j <= 17; ++j){
        for(int i = 2; i <= numFuncionarios; ++i){

            int chefeIntermediario = up[i][j - 1];
            up[i][j] = up[chefeIntermediario][j - 1];
        }
    }
    
    for(int i = 0; i < numConsultas; ++i){

        int nodo1, nodo2;
        cin >> nodo1 >> nodo2;

        if(nivelFuncionario[nodo1] > nivelFuncionario[nodo2]) swap(nodo1, nodo2);

        int diff = nivelFuncionario[nodo2] - nivelFuncionario[nodo1];

        //nivelar nodo2 (mais fundo) com nodo1
        for(int j = 0; j <= 17; ++j){

            if(diff & (1 << j)){
                nodo2 = up[nodo2][j];
            }
        }

        //nodo 1 era o proprio LCA
        if(nodo2 == nodo1) cout << nodo2 << '\n';

        else{
            for(int j = 17; j >= 0; --j){
                if(up[nodo1][j] != up[nodo2][j]){
                    nodo1 = up[nodo1][j];
                    nodo2 = up[nodo2][j];
                }
            }

            cout << up[nodo1][0] << '\n';
        }
    }
}