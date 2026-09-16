#include<bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char direction[] = {'D', 'U', 'R', 'L'};

int main(){
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int linhas, colunas;
    cin >> linhas >> colunas;

    //legal isso
    vector<string> labirinto(linhas); //n precisa declar as colunas, string eh dinamico
    vector<vector<int>> distancias(linhas, vector<int>(colunas, -1));
    vector<vector<char>> caminho(linhas, vector<char>(colunas));
    queue<pair<int, int>> fila;

    for(int i = 0; i < linhas; ++i){
        cin >> labirinto[i];
    }
    for(int i = 0; i < linhas; ++i){
        for(int j = 0; j < colunas; ++j){
            if(labirinto[i][j] == 'A'){
                fila.push({i, j}); //incio
                distancias[i][j] = 0;
            }
        }
    }
    bool achou = false;
    int ans = -1;
    int xB;
    int yB;

    while(!fila.empty()){
        int a = fila.front().first;
        int b = fila.front().second;

        if(labirinto[a][b] == 'B'){
            ans = distancias[a][b];
            achou = true;
            xB = a;
            yB = b;
            break;
        }

        for(int i = 0; i < 4; ++i){
            int newA = a + dx[i];
            int newB = b + dy[i];
            char movimento = direction[i];

            if(newA < linhas && newA >= 0 && newB < colunas && newB >= 0 &&
            labirinto[newA][newB] != '#' && distancias[newA][newB] == -1){
                fila.push({newA, newB});
                distancias[newA][newB] = distancias[a][b] + 1;
                caminho[newA][newB] = movimento;
            }
        }
        fila.pop();
    }

    if(achou){
        cout << "YES" << '\n' << ans << '\n';

        string path;
        for(int i = 0; i < ans; ++i){
            char curr = caminho[xB][yB];
            path.push_back(curr);
            if(curr == 'D') xB--;
            else if(curr == 'U') xB++;
            else if(curr == 'R') yB--;
            else if(curr == 'L') yB++;
        }
        reverse(path.begin(), path.end());
        cout << path << '\n';
    }
    else cout << "NO";
}