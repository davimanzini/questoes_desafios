#include<bits/stdc++.h>
using namespace std;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    priority_queue<int> metadeInferior;
    priority_queue<int, vector<int>, greater<int>> metadeSuperior;

    int total;
    cin >> total;

    for(int i = 0; i < total; ++i){
        
        int apto;
        cin >> apto;
        
        if(i == 0){
            metadeInferior.push(apto);
            cout << metadeInferior.top() << '\n';
        }
        else{
            if(apto > metadeInferior.top()){
                metadeSuperior.push(apto);
            }
            else{
                metadeInferior.push(apto);
            }
            if(metadeInferior.size() > metadeSuperior.size() + 1){
                int aux = metadeInferior.top();
                metadeInferior.pop();
                metadeSuperior.push(aux);
            }
            else if(metadeSuperior.size() > metadeInferior.size()){
                int aux = metadeSuperior.top();
                metadeSuperior.pop();
                metadeInferior.push(aux);
            }
            cout << metadeInferior.top() << '\n';
        }
    }
}