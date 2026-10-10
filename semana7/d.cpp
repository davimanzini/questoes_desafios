#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int numCidades, numEstradas;
    cin >> numCidades >> numEstradas;
    vector<vector<pair<int, int>>> adjacents(numCidades + 1);

    for(int i = 0; i < numEstradas; ++i){
        int a, b, inclinacao;
        cin >> a >> b >> inclinacao;
        adjacents[a].push_back({b, inclinacao});
        adjacents[b].push_back({a, inclinacao});
    }

    int numConsultas;
    cin >> numConsultas;
    for(int i = 0; i < numConsultas; ++i){
        int origem, destino;
        cin >> origem >> destino;

        // p1 eh a inclinacao e p2 eh o destino
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fprio;
        vector<int> maxInclinacoes(numCidades + 1, INF);
        maxInclinacoes[origem] = 0;
        fprio.push({0, origem});

        while(!fprio.empty()){

            auto [inc, atual] = fprio.top();
            fprio.pop();

            if(inc > maxInclinacoes[atual]) continue;

            if(atual == destino){
                cout << inc << '\n';
                break;
            }

            for(auto adjacente : adjacents[atual]){
                
                int nextInc = adjacente.second;
                int nextDest = adjacente.first;

                int currInc = max(maxInclinacoes[atual], nextInc);

                if(currInc < maxInclinacoes[nextDest]){
                    maxInclinacoes[nextDest] = currInc;
                    fprio.push({currInc, nextDest}); //coloca na fprio se for melhor
                }
            }

        }
        
    }
}