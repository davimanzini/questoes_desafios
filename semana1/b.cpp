#include<iostream>
using namespace std;

int main(){
    int tamanho;
    int movimentos;
    int posicao;
    cin >> tamanho >> movimentos >> posicao;
    
    for(int i = 0; i < movimentos; ++i){
        int left;
        int right;
        cin >> left >> right;
        int dist = tamanho - right;
        int range = right - left + 1;
        if(posicao >= left && posicao <= right){
            posicao += dist;
        }
        else if(posicao > right){
            posicao -= range;
        }
    }
    cout << posicao << '\n';
}