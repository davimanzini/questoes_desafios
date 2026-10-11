#include<bits/stdc++.h>
using namespace std;
#define INF 987654321

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int numCidades, numEstradas;
    cin >> numCidades >> numEstradas;

    vector<vector<int>> distancias(numCidades, vector<int>(numCidades, INF));
    for(int i = 0; i < numCidades; ++i){
        distancias[i][i] = 0;
    }

    for(int i = 0; i < numEstradas; ++i){
        int origem, destino, dist;
        cin >> origem >> destino >> dist;

        if(dist < distancias[origem][destino]){
            distancias[origem][destino] = dist;
            distancias[destino][origem] =  dist;
        }
    }

    //aplicacao do floyd-warshall
    for(int k = 0; k < numCidades; ++k){
        for(int i = 0; i < numCidades; ++i){
            for(int j = 0; j < numCidades; ++j){
                int d1 = distancias[i][j];
                int d2 = distancias[i][k];
                int d3 = distancias[k][j];

                if(d2 == INF || d3 == INF) continue;

                if(d2 + d3 < d1){
                    distancias[i][j] = d2 + d3;
                    distancias[j][i] = d2 + d3;
                }
            }
        }
    }

    int ans = INF;

    for(int i = 0; i < numCidades; ++i){
        int maior = 0;
        for(int j = 0; j < numCidades; ++j){
            int curr = distancias[i][j];
            if(curr > maior) maior = curr;
        }
        if(maior < ans) ans = maior;
    }
    cout << ans << '\n';
}