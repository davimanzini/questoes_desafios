#include<bits/stdc++.h>
using namespace std;

//encontra o pai de um vertice
int find(vector<int> &pais, int x){
    if(pais[x] == x) return x;
    return pais[x] = find(pais, pais[x]);
}

//une dois vertices
void unite(vector<int> &pais, int u, int v){
    int paiU = find(pais, u);
    int paiV = find(pais, v);

    if(paiU != paiV){
        pais[paiU] = paiV;
    }
}

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int numPcs, numConex, numCortes;
    cin >> numPcs >> numConex >> numCortes;

    vector<int> pais(numPcs + 1);
    for(int i = 1; i <= numPcs; ++i){
        pais[i] = i;
    }

    vector<pair<int, int>> conexoes;
    vector<pair<int, int>> cortes;
    set<pair<int, int>> listaNegra;

    for(int i = 0; i < numConex; ++i){
        int pc1, pc2;
        cin >> pc1 >> pc2;
        conexoes.push_back(make_pair(min(pc1, pc2), max(pc1, pc2)));
    }

    for(int i = 0; i < numCortes; ++i){
        int pc1, pc2;
        cin >> pc1 >> pc2;
        cortes.push_back(make_pair(min(pc1, pc2), max(pc1, pc2)));
        listaNegra.insert(make_pair(min(pc1, pc2), max(pc1, pc2)));
    }

    int componentesFinais = numPcs;
    for(int i = 0; i < numConex; ++i){
        if(listaNegra.find(conexoes[i]) == listaNegra.end()){
            if(find(pais, conexoes[i].first) != find(pais, conexoes[i].second)){
                componentesFinais--;
            }
            unite(pais, conexoes[i].first, conexoes[i].second);
        }
    }

    vector<int> respostas(numCortes);


    for(int i = numCortes - 1; i >= 0; --i){

        respostas[i] = componentesFinais;

        if(find(pais, cortes[i].first) != find(pais, cortes[i].second)){
            unite(pais, cortes[i].first, cortes[i].second);
            componentesFinais--;
        }
    }

    for(int i = 0; i < numCortes; ++i){
        cout << respostas[i] << ' ';
    }
    cout << '\n';
}