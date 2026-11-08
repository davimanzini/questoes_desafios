#include<bits/stdc++.h>
using namespace std;

int timer = 1;
int idComponente = 1;

void dfs(int verticeAtual, vector<vector<int>> &adjacentes, stack<int> &stck, vector<int> &tin,
     vector<int> &lowLink, vector<bool> &inStack, vector<int> &pais){

    tin[verticeAtual] = timer;
    lowLink[verticeAtual] = timer;
    timer++;

    stck.push(verticeAtual);
    inStack[verticeAtual] =  true;

    for(int vizinho : adjacentes[verticeAtual]){

        if(tin[vizinho] == -1){
            dfs(vizinho, adjacentes, stck, tin, lowLink, inStack, pais);
            lowLink[verticeAtual] = min(lowLink[verticeAtual], lowLink[vizinho]);
        }

        //nodo ja visitado
        else{
            if(inStack[vizinho]){
                lowLink[verticeAtual] = min(lowLink[verticeAtual], tin[vizinho]);
            }
        }
    }
    //se sim, ele é o vertice "chefe"
    if(lowLink[verticeAtual] == tin[verticeAtual]){

        int topo;

        do{
            topo = stck.top();
            stck.pop();
            inStack[topo] = false;
            pais[topo] = idComponente;

        } while(topo != verticeAtual);

        idComponente++;
    }
}

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int numCidades, numConexoes;
    cin >> numCidades >> numConexoes;

    vector<vector<int>> adjacentes(numCidades + 1);


    for(int i = 0; i < numConexoes; ++i){

        int origem, destino;
        cin >> origem >> destino;

        adjacentes[origem].push_back(destino);
    }

    vector<int> tin(numCidades + 1, -1);
    vector<int> lowLink(numCidades + 1, -1);

    stack<int> stck;
    vector<bool> inStack(numCidades + 1, false);
    
    vector<int> pais(numCidades + 1);
    for(int i = 1; i <= numCidades; ++i){
        pais[i] = i;
    }

    for(int i = 1; i <= numCidades; ++i){
        
        //se o vertice ja foi visitado
        if(tin[i] != -1) continue;
        dfs(i, adjacentes, stck, tin, lowLink, inStack, pais);
    }

    //edge case: um unico componente
    if(idComponente == 2) cout << 0 << '\n';

    else{

        vector<int> qtdSaida(idComponente, 0);
        vector<int> qtdEntrada(idComponente, 0);

        for(int i = 1; i <= numCidades; ++i){
            
            for(int vizinho : adjacentes[i]){
                if(pais[i] != pais[vizinho]){
                    qtdSaida[pais[i]]++;
                    qtdEntrada[pais[vizinho]]++;
                }
            }
        }

        int saidasFaltantes = 0;
        int entradasFaltantes = 0;

        for(int i =  1; i < idComponente; ++i){
            if(qtdSaida[i] == 0) saidasFaltantes++;
            if(qtdEntrada[i] == 0) entradasFaltantes++;
        }

        int ans = max(saidasFaltantes, entradasFaltantes);
        cout << ans << '\n';
    }
}