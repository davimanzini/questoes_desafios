#include<bits/stdc++.h>
using namespace std;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    map<string, pair<int, int>> mp;

    int total;
    cin >> total;

    for(int i = 0; i < total; ++i){
        string equipe;
        cin >> equipe;
        mp[equipe];
    }

    int numRegistros;
    cin >> numRegistros;

    for(int i = 0; i < numRegistros; ++i){
        string nome;
        int baloes;
        int tempo;
        cin >> nome >> baloes >> tempo;
        mp[nome].first += baloes;
        mp[nome].second += tempo;
    }

    vector<tuple<int, int, string>> placar;

    for(auto p : mp){
        placar.push_back(make_tuple(-p.second.first, p.second.second, p.first));
    }
    sort(placar.begin(), placar.end());

    for(int i = 0; i < total; ++i){
        cout << get<2>(placar[i]) << '\n';
    }
}