#include<bits/stdc++.h>
using namespace std;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int tamVet, numConsultas;
    cin >> tamVet >> numConsultas;

    vector<int> vet(tamVet + 1);

    for(int i = 1; i <= tamVet; ++i){
        int currVal;
        cin >> vet[i];
    }

    for(int i = 0; i < numConsultas; ++i){

        int left, right, idxTarget;
        cin >> left >> right >> idxTarget;

        vector<int> curr;
        for(int j = left; j <= right; ++j){
            curr.push_back(vet[j]);
        }

        sort(curr.begin(), curr.end());
        int target = curr[idxTarget - 1];

        cout << target << '\n';
    }
}