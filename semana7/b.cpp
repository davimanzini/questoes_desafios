#include<bits/stdc++.h>
using namespace std;

#define INF 1e18
#define ll long long

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int numParadas;
    cin >> numParadas;

    vector<ll> lotacao(numParadas + 1);
    for(int i = 1; i <= numParadas; ++i){
        cin >> lotacao[i];
    }

    //vetor de distancia em relacao a posicao 1
    vector<ll> distancias(numParadas + 1, INF);
    distancias[1] = 0;

    vector<tuple<int, int, ll>> arestas;
    int numEstradas;
    cin >> numEstradas;

    for(int i = 0; i < numEstradas; ++i){
        int origem, destino;
        cin >> origem >> destino;
        ll dist = lotacao[destino] - lotacao[origem];
        arestas.push_back({origem, destino, dist});
    }

    //pq rodamos n - 1 vezes?
    for(int i = 0; i < numParadas - 1; ++i){
        for(auto aresta : arestas){
            auto [origem, destino, distancia] = aresta;
            if(distancias[origem] != INF){
                distancias[destino] = min(distancias[destino], distancias[origem] + distancia);
            }
        }
    }

    //revisar isso melhor
    //roda de novo para checar ciclos de dinheiro infinito
    for(int i = 0; i < numParadas - 1; ++i){
        for(auto aresta : arestas){
            auto [origem, destino, distancia] = aresta;
            //revisar pq precisa verificar isso aqui de novo
            //resposta: pq podem ter nós inalcançaveis a partir da origem
            if(distancias[origem] != INF){
                //se ja estiver contaminado ou ainda der pra diminuir a distancia (o que nao deveria ser possivel)
                if(distancias[origem] == -INF || distancias[origem] + distancia < distancias[destino]){
                    distancias[destino] = -INF;
                }
            }
        }
    }

    int numConsultas;
    cin >> numConsultas;

    for(int i = 0; i < numConsultas; ++i){
        int currDest;
        cin >> currDest;
        if(distancias[currDest] < 3){
            cout << "Não, Edsger..." << '\n';
        }
        else cout << distancias[currDest] << '\n';
    }
}