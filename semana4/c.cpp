#include<bits/stdc++.h>
using namespace std;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    vector<pair<int, int>> horarios;
    int total;
    cin >> total;

    for(int i = 0; i < total; ++i){
        int inicio;
        int fim;
        cin >> inicio >> fim;
        horarios.push_back(make_pair(fim, inicio));
    }
    sort(horarios.begin(), horarios.end());

    int ans = 1;
    int fimPrev = horarios[0].first;

    for(int j = 1; j < total; ++j){
        int currComeco = horarios[j].second;
        if(currComeco >= fimPrev){
            ans++;
            fimPrev = horarios[j].first;
        } 
    }

    cout << ans << '\n';
}