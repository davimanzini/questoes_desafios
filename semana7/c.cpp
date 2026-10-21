#include<bits/stdc++.h>
using namespace std;

#define INF 987654321

int main(){
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int numCidades, numEstradas, tamRota, origem;
    cin >> numCidades >> numEstradas >> tamRota >> origem;

    vector<vector<pair<int, int>>> adjacents(numCidades);
    vector<int> distsDestino(tamRota, 0);

    for(int i = 0; i < numEstradas; ++i){

        int u, v, custo;
        cin >> u >> v >> custo;

        if(u < tamRota && v < tamRota){
            if(abs(u - v) == 1){
                distsDestino[min(u, v)] = custo;
            }
        }

        adjacents[u].push_back({custo, v});
        adjacents[v].push_back({custo, u});
    }

    for(int i = tamRota - 2; i >= 0; --i){
        distsDestino[i] += distsDestino[i + 1];
    }

    vector<int> distancias(numCidades, INF);
    distancias[origem] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fprio;
    fprio.push({0, origem});

    while(!fprio.empty()){

        auto [dist, atual] = fprio.top();
        fprio.pop();

        if(atual < tamRota) continue;
        if(dist > distancias[atual]) continue;

        for(auto [custo, vizinho] : adjacents[atual]){

            int novoCusto = dist + custo;

            if(novoCusto < distancias[vizinho]){
                distancias[vizinho] = novoCusto;
                fprio.push({novoCusto, vizinho});
            }
        }
    }

    int minimo = distancias[tamRota - 1];

    for(int i = 0; i < tamRota - 1; ++i){
        if(distancias[i] + distsDestino[i] < minimo){
            minimo = distancias[i] + distsDestino[i];
        }
    }

    cout << minimo << '\n';
}