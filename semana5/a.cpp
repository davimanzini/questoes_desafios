#include<bits/stdc++.h>
using namespace std;

int dp[100001];
int escolhas[100001];


int recursive(int tamAtual, vector<int> &comprimentos){
    
    if(tamAtual == 0) return 0;

    if(dp[tamAtual] != -1) return dp[tamAtual];

    int menor = 1e9;
    int melhorCorte = -1;

    for(int i = 0; i < comprimentos.size(); ++i){
        if(comprimentos[i] <= tamAtual){
            
            int nextTam = tamAtual - comprimentos[i];
            int retorno = recursive(nextTam, comprimentos);
            
            if(retorno != 1e9){

                int custo_atual = 1 + retorno;

                if(custo_atual < menor){
                    menor = custo_atual;
                    melhorCorte = comprimentos[i];
                }
            }
        }
    }
    dp[tamAtual] = menor;
    escolhas[tamAtual] = melhorCorte;

    return menor;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int numPolentas;
    int numComprimentos;
    cin >> numPolentas >> numComprimentos;
    vector<int> comprimentos(numComprimentos);
    
    for(int i =0; i < numComprimentos; ++i){
        cin >> comprimentos[i];
    }
    sort(comprimentos.rbegin(), comprimentos.rend());

    memset(dp, -1, sizeof(dp));
    memset(escolhas, -1, sizeof(escolhas));

    for(int i = 0; i < numPolentas; ++i){
        int tamAtual;
        cin >> tamAtual;

        int resposta = recursive(tamAtual, comprimentos);
        if(resposta == 1e9){
            cout << "NAO" << '\n';
        }
        else{
            int atual = tamAtual;
            while(atual > 0){
                cout << escolhas[atual] << " ";
                atual -= escolhas[atual];
            }
            cout << '\n';
        }

    }
}