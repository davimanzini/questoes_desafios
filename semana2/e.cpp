#include<bits/stdc++.h>
using namespace std;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int total;
    cin >> total;
    vector<int> cidades(total);

    for(int i = 0; i < total; ++i){
        cin >> cidades[i];
    }
    
    int i = 0;
    int j = 0;
    int maxCidades = 0;
    set<int> set;

    while(j < total){
        int cidadeAtual = cidades[j];

        if(set.count(cidadeAtual) == 0){
            set.insert(cidadeAtual);
            j++;
            maxCidades = max(maxCidades, j - i);
        }
        else{
            set.erase(cidades[i]);
            i++;
        }
    }

    cout << maxCidades << '\n';
}