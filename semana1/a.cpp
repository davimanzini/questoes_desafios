#include<bits/stdc++.h>
using namespace std;

int main(){
    int numTestes;
    cin >> numTestes;

    for(int i = 0; i < numTestes; ++i){
        int numAlunos;
        cin >> numAlunos;
        unordered_map<int, int> mp;
        for(int j = 0; j < numAlunos; ++j){
            int aluno;
            cin >> aluno;
            mp[aluno]++;
        }
        cout << mp.size() << '\n';
    }
}