#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int numJogadores;
    int numPartidas;
    cin >> numJogadores >> numPartidas;

    vector<long long> distancias(numJogadores + 1, 0);
    for(int i = 2; i < numJogadores + 1; ++i){
        cin >> distancias[i];
        distancias[i] += distancias[i - 1];
    }

    vector<pair<int, int>> vencedores(numJogadores + 1);
    for(int i = 1; i <= numJogadores; ++i){
        vencedores[i] = {0, -i}; 
    }

    //partidas
    for(int i = 0; i < numPartidas; ++i){
        
        int anfitriao;
        int numParticipantes;
        cin >> anfitriao >> numParticipantes;
        pair<long long, int> maiorDistQtd = {-1, 0};
        int vencedor = -1;

        for(int j = 0; j < numParticipantes; ++j){
            
            int currParticipante;
            cin >> currParticipante;

            long long currDist = abs(distancias[currParticipante] - distancias[anfitriao]);
            if(currDist == maiorDistQtd.first) maiorDistQtd.second++;
            else if(currDist > maiorDistQtd.first){
                maiorDistQtd.first = currDist;
                maiorDistQtd.second = 1;
                vencedor = currParticipante;
            }
        }

        if(maiorDistQtd.second == 1 && vencedor != -1){
            vencedores[vencedor].first ++;
        }
    }

    sort(vencedores.begin() + 1, vencedores.end());
    int ans = -vencedores[numJogadores].second;
    cout << ans << '\n';
}