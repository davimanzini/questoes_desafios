#include<bits/stdc++.h>
using namespace std;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    string x = "";
    int dinheiro;
    cin >> dinheiro;
    int menor = 1e7;
    vector<int> valores;
    for(int i = 0; i < 9; ++i){
        int currVal;
        cin >> currVal;
        valores[i] = currVal;
        if(currVal < menor) menor = currVal;
    }
    int j = 8;
    int maxAlgs = dinheiro / 2;
    for(int i = 0; i < maxAlgs; ++i){
        while(dinheiro < valores[j] || dinheiro - valores[j] < (maxAlgs - i) * menor){
            j--;
        }
        dinheiro - valores[j];
        x += to_string(j + 1);
    }
    cout << x << "\n";
}