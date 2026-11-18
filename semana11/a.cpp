#include<bits/stdc++.h>
using namespace std;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int numPlanetas, numConsultas;
    cin >> numPlanetas >> numConsultas;

    int up[numPlanetas + 1][30];

    for(int i = 1; i <= numPlanetas; ++i){

        int destino;
        cin >> destino;

        up[i][0] = destino;
    }

    for(int j = 1; j < 30; j++) {

        for(int i = 1; i <= numPlanetas; i++) {
            
            int planeta_intermediario = up[i][j-1];
            up[i][j] = up[planeta_intermediario][j-1];
        }
    }

    for(int i = 0; i < numConsultas; ++i){

        int origem, saltos;
        cin >> origem >> saltos;
        int fim = origem;

        for(int j = 0; j < 30; ++j){

            if(saltos & (1 << j)){
                fim = up[fim][j];
            }
        }

        cout << fim << '\n';
    }
}