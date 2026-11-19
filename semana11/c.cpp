#include<bits/stdc++.h>
using namespace std;

int main(){
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int numLocais;
    cin >> numLocais;

    vector<vector<pair<int, long long>>> up(numLocais, vector<pair<int, long long>>(18));
    up[0][0].first = 0;

    vector<int> nivelLocal(numLocais);
    nivelLocal[0] = 0;
    
    for(int i = 1; i < numLocais; ++i){

        int currDestino, currDist;
        cin >> currDestino >> currDist;

        up[i][0].first = currDestino;
        up[i][0].second = currDist;
        nivelLocal[i] = nivelLocal[currDestino] + 1;
    }

    for(int j = 1; j <= 17; ++j){
        for(int i = 2; i < numLocais; ++i){

            int localIntermediario = up[i][j - 1].first;
            long long custoIntermediario = up[i][j - 1].second;
            up[i][j].first = up[localIntermediario][j - 1].first;
            up[i][j].second = custoIntermediario + up[localIntermediario][j - 1].second;
        }
    }
    
    int numConsultas;
    cin >> numConsultas;

    for(int i = 0; i < numConsultas; ++i){

        int nodo1, nodo2;
        cin >> nodo1 >> nodo2;

        if(nivelLocal[nodo1] > nivelLocal[nodo2]) swap(nodo1, nodo2);

        int diff = nivelLocal[nodo2] - nivelLocal[nodo1];

        long long count = 0;

        //nivelar nodo2 (mais fundo) com nodo1
        for(int j = 0; j <= 17; ++j){

            if(diff & (1 << j)){
                count += up[nodo2][j].second;
                nodo2 = up[nodo2][j].first;
            }
        }

        //nodo 1 era o proprio LCA
        if(nodo2 == nodo1) cout << count << '\n';

        else{
            for(int j = 17; j >= 0; --j){
                if(up[nodo1][j].first != up[nodo2][j].first){
                    
                    count += up[nodo1][j].second;
                    nodo1 = up[nodo1][j].first;
                    count += up[nodo2][j].second;
                    nodo2 = up[nodo2][j].first;
                }
            }

            count += up[nodo1][0].second;
            count += up[nodo2][0].second;

            cout << count << '\n';
        }
    }
}