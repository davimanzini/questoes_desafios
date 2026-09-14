#include<bits/stdc++.h>
using namespace std;

int recursive(int currNode, int parentNode, vector<vector<int>> &adjacents, int &maxDiametro){

    int max1 = 0;
    int max2 = 0;

    for(int i = 0; i < adjacents[currNode].size(); ++i){
       
       if(parentNode == adjacents[currNode][i]) continue; 
       int currPath = recursive(adjacents[currNode][i], currNode, adjacents, maxDiametro);

       if(currPath > max1){
        max2 = max1;
        max1 = currPath;
       }
       else if(currPath > max2) max2 = currPath;
    }

    int currNodeMax = max1 + max2;
    if(currNodeMax > maxDiametro) maxDiametro = currNodeMax;

    return max(max1, max2) + 1;
}

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int qtd;
    cin >> qtd;
    
    vector<vector<int>> adjacents(qtd + 1);

    for(int i = 0; i < qtd - 1; ++i){
        int curr, conection;
        cin >> curr >> conection;
        adjacents[curr].push_back(conection);
        adjacents[conection].push_back(curr); //grafo não direcionado
    }

    int maxDiametro = -1;
    recursive(1, 0, adjacents, maxDiametro); //pai é 0, pq n tem adjacents[0]
    
    cout << maxDiametro << '\n';
}