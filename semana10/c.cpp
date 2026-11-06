#include<bits/stdc++.h>
using namespace std;

int numPontes = 0;
int contador = 1;

void dfs(int atual, int pai, vector<int> &tin, vector<int> &lowLink, vector<vector<int>> &adjacents){
    
    tin[atual] = contador;
    lowLink[atual] = contador;
    contador++;

    for(int vizinho : adjacents[atual]){
        if(vizinho == pai) continue;

        if(tin[vizinho] == -1){
            dfs(vizinho, atual, tin, lowLink, adjacents);
            lowLink[atual] = min(lowLink[atual], lowLink[vizinho]);
            if(lowLink[vizinho] > tin[atual]) numPontes++;
        }
        else{
            lowLink[atual] = min(lowLink[atual], tin[vizinho]);
        }
    }
}

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int numTestes;
    cin >> numTestes;

    for(int i = 0; i < numTestes; ++i){

        int numVertices, numConexoes;
        cin >> numVertices >> numConexoes;
        vector<vector<int>> adjacents(numVertices + 1);
        vector<int> tin(numVertices + 1, -1);
        vector<int> lowLink(numVertices + 1, -1);


        for(int j = 0; j < numConexoes; ++j){
            
            int u, v;
            cin >> u >> v;
            adjacents[u].push_back(v);
            adjacents[v].push_back(u);

        }
        for(int v = 1; v <= numVertices; ++v){
            if(tin[v] == -1){
                dfs(v, 0, tin, lowLink, adjacents);
            }
        }
        cout << numPontes << '\n';
        numPontes = 0;
        contador = 1;
    }
    
}