#include<bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int linhas, colunas, tempo;
    cin >> linhas >> colunas >> tempo;

    vector<vector<int>> floresta(linhas, vector<int>(colunas));
    vector<vector<int>> vizinhosFogo(linhas, vector<int>(colunas, 0));
    vector<vector<int>> tempoQueimando(linhas, vector<int>(colunas, -1));
    queue<pair<int, int>> fila;


    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; ++j){
            cin >> floresta[i][j];
            if(floresta[i][j] == 0){
                fila.push({i, j});
                tempoQueimando[i][j] = 0;
            }
        }
    }
    
    while(!fila.empty()){

        int a = fila.front().first;
        int b = fila.front().second;
        fila.pop();

        if(tempoQueimando[a][b] >= tempo) break;

        for(int k = 0; k < 8; ++k){

            int newX = a + dx[k];
            int newY = b + dy[k];

            //se a posicao eh valida
            if(newX < linhas && newX >= 0 &&
            newY < colunas && newY >= 0){

                if(floresta[newX][newY] > 0){

                    if(k <= 3){ //movimentos em linha reta
                        vizinhosFogo[newX][newY]++;
                    }
                    else{ //diagonais
                        if(floresta[newX][newY] == 1){
                            vizinhosFogo[newX][newY]++;
                        }
                    }

                    bool vaiQueimar = false;
                    int tipoArvore = floresta[newX][newY];
                    int qtdFogo = vizinhosFogo[newX][newY];

                    if(tipoArvore == 1 && qtdFogo >= 1){
                        vaiQueimar = true;
                    }
                    else if(tipoArvore == 2 && qtdFogo >= 1){
                        vaiQueimar = true;
                    }
                    else if(tipoArvore == 3 && qtdFogo >= 2){
                        vaiQueimar = true;
                    }
                    else if(tipoArvore == 4 && qtdFogo >= 3){
                        vaiQueimar = true;
                    }
                    
                    if(vaiQueimar){
                        floresta[newX][newY] = 0;
                        tempoQueimando[newX][newY] = tempoQueimando[a][b] + 1;
                        fila.push({newX, newY});
                    }
                }
            }
        }
    }
    
    int count = 0;
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; ++j){
            if(floresta[i][j] == 0){
                count++;
            }
        }
    }
    cout << count << '\n';
}