#include<bits/stdc++.h>
using namespace std;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int numFuncionarios, numConsultas;
    cin >> numFuncionarios >> numConsultas;

    int up[numFuncionarios + 1][20];

    // raiz de tudo, pai de si mesmo
    up[0][0] = 0;
    // "pai" do diretor geral é a raiz
    up[1][0] = 0;

    for(int i = 2; i <= numFuncionarios; ++i){
        
        int currChefe;
        cin >> currChefe;

        up[i][0] = currChefe;
    }

    for(int j = 1; j < 20; j++) {

        for(int i = 0; i <= numFuncionarios; i++) {
            
            int chefeIntermediario = up[i][j-1];
            up[i][j] = up[chefeIntermediario][j-1];
        }
    }

    for(int i = 0; i < numConsultas; ++i){

        int funcAtual, numPulos;
        cin >> funcAtual >> numPulos;

        int fim = funcAtual;

        for(int j = 0; j < 20; ++j){

            if(numPulos & (1 << j)){
                fim = up[fim][j];
            }
        }
        
        if(fim == 0) cout << -1 << '\n';
        else cout << fim << '\n';
    }
}