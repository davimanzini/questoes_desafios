#include<bits/stdc++.h>
using namespace std;

int main(){
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int numVertices, numArestas;
    cin >> numVertices >> numArestas;

    vector<vector<int>> adjacentes(numVertices + 1);
    vector<int> grauEntrada(numVertices + 1, 0);

    for(int i = 0; i < numArestas; ++i){
        int origem, destino;
        cin >> origem >> destino;

        adjacentes[origem].push_back(destino);
        grauEntrada[destino]++;
    }

    vector<int> origemMsg(numVertices + 1, 0);
    queue<int> fila;

    for(int i = 1; i <= numVertices; ++i){
        if(grauEntrada[i] == 0){
            origemMsg[i] = i;
            fila.push(i);
        }
    }

    while(!fila.empty()){
        int atual = fila.front();
        fila.pop();

        for(int vizinho : adjacentes[atual]){
            if(origemMsg[vizinho] == 0){
                origemMsg[vizinho] = origemMsg[atual];
                fila.push(vizinho);
            }
            else if(origemMsg[vizinho] != -1){
                if(origemMsg[vizinho] != origemMsg[atual]){
                    origemMsg[vizinho] = -1;
                    fila.push(vizinho);
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= numVertices; ++i){
        if(origemMsg[i] == -1) ans++;
    }

    cout << ans << '\n';

    return 0;
}