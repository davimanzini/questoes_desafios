#include<bits/stdc++.h>
using namespace std;

#define INF 987654321

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int numVertices, numArestas;
    cin >> numVertices >> numArestas;

    vector<int> distancias(numVertices, INF);
    distancias[0] = 0;

    vector<vector<pair<int, int>>> adjacents(numVertices);

    for(int i = 0; i < numArestas; ++i){

        int origem, destino, dist;
        cin >> origem >> destino >> dist;

        adjacents[origem].push_back({dist, destino});
        adjacents[destino].push_back({dist, origem});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fprio;
    fprio.push({0, 0});

    while(!fprio.empty()){

        auto [dist, atual] = fprio.top();
        fprio.pop();

        if(dist > distancias[atual]) continue;

        for(auto [distVizinho, vizinho] : adjacents[atual]){

            int novaDist = dist + distVizinho;

            if(novaDist < distancias[vizinho]){
                distancias[vizinho] = novaDist;
                fprio.push({novaDist, vizinho});
            }
        }
    }

    int distMinima = distancias[numVertices - 1];
    int qtdFlores = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> backtrack;
    backtrack.push({distMinima, numVertices - 1});
    vector<bool> explorados(numVertices);
    explorados[numVertices - 1] = true;

    while(!backtrack.empty()){

        auto [dist, atual] = backtrack.top();
        backtrack.pop();

        for(auto [distVizinho, vizinho] : adjacents[atual]){
            if(distVizinho + distancias[vizinho] == dist){
                qtdFlores += distVizinho;
                if(!explorados[vizinho]){
                    backtrack.push({distancias[vizinho], vizinho});
                    explorados[vizinho] = true;
                }
            }
        }
    }
    cout << 2 * qtdFlores << '\n';
}