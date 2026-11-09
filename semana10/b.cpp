#include<bits/stdc++.h>
using namespace std;

void dfs(int verticeAtual, vector<vector<int>> &revAdjacentes, vector<int> &origemMsg){

    //sendo processado
    origemMsg[verticeAtual] = -2;

    for(int vizinho : revAdjacentes[verticeAtual]){

        if(origemMsg[vizinho] == -2) continue;

        if(origemMsg[vizinho] == 0){
            dfs(vizinho, revAdjacentes, origemMsg);
        }

        if(origemMsg[vizinho] == -1){
            origemMsg[verticeAtual] = -1;
        }
        else{
            if(origemMsg[verticeAtual] == -2){
                origemMsg[verticeAtual] = origemMsg[vizinho];
            }
            else if(origemMsg[verticeAtual] != -1){
                if(origemMsg[verticeAtual] != origemMsg[vizinho]){
                    origemMsg[verticeAtual] = -1;
                }
            }
        }
    }
    if(origemMsg[verticeAtual] == -2){
        origemMsg[verticeAtual] = 0;
    }
}

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int numVertices, numArestas;
    cin >> numVertices >> numArestas;

    vector<bool> isFont(numVertices + 1, true);
    vector<int> origemMsg(numVertices + 1, 0);

    vector<vector<int>> revAdjacentes(numVertices + 1);
    for(int i = 0; i < numArestas; ++i){
        int origem, destino;
        cin >> origem >> destino;

        revAdjacentes[destino].push_back(origem);
        isFont[destino] = false;
    }

    for(int i = 1; i <= numVertices; ++i){
        if(isFont[i]) origemMsg[i] = i;
    }

    for(int i = 1; i <= numVertices; ++i){

        //se ja passou
        if(origemMsg[i] != 0) continue;

        dfs(i, revAdjacentes, origemMsg);
    }

    int ans = 0;
    for(int i = 1; i <= numVertices; ++i){
        if(origemMsg[i] == -1) ans++;
    }

    cout << ans << '\n';
}