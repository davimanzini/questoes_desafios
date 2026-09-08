#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int minScore = 1;
int maxScore;
int numScores;
vector<int> scores;

int recursive(int valorAtual, int indiceAtual, vector<vector<int>> &dp){

    if(valorAtual > maxScore || valorAtual < minScore) return 0;

    //ultimo numero do vetor/caso base
    if(indiceAtual == numScores -1){
        if(scores[indiceAtual] == 0) return 1;
        if(scores[indiceAtual] == valorAtual) return 1;
        else return 0;
    }
    
    if(scores[indiceAtual] != valorAtual && scores[indiceAtual] != 0) return 0;

    if(dp[indiceAtual][valorAtual] != -1) return dp[indiceAtual][valorAtual];

    int plusPath = recursive(valorAtual + 1, indiceAtual + 1, dp) % MOD;
    int equalPath = recursive(valorAtual, indiceAtual + 1, dp) % MOD;
    int minusPath = recursive(valorAtual - 1, indiceAtual + 1, dp) % MOD;

    int somaCaminhos = (plusPath + equalPath) % MOD;
    somaCaminhos = (somaCaminhos + minusPath) % MOD;
    dp[indiceAtual][valorAtual] = somaCaminhos;

    return somaCaminhos;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> numScores >> maxScore;

    for(int i = 0; i < numScores; ++i){
        int currScore;
        cin >> currScore;
        scores.push_back(currScore);
    }

    vector<vector<int>> dp(numScores, vector<int>(maxScore + 1, -1));

    if(scores[0] == 0){
        int soma = 0;
        for(int i = 1; i <= maxScore; ++i){
            soma += recursive(i, 0, dp);
            soma = soma % MOD;
        }
        cout << soma <<'\n';
    }
    else{
        int ans = recursive(scores[0], 0, dp);
        cout << ans << '\n';
    }
}