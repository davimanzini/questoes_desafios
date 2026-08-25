#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int testes;
    cin >> testes;

    for(int i = 0; i < testes; ++i){
        long long numDiretorios; long long numArquivos; long long maxSize;
        cin >> numDiretorios >> numArquivos >> maxSize;

        vector<long long> originalSizes;
        for(int j = 0; j < numDiretorios; ++j){
            long long original;
            cin >> original;
            originalSizes.push_back(original);
        }

        vector<long long> currSizes = originalSizes;
        vector<int> alterados;

        for(int k = 0; k < numArquivos; ++k){
            long long currDir; long long fileSize;
            cin >> currDir >> fileSize;
            currSizes[currDir - 1] += fileSize;
            
            alterados.push_back(currDir - 1);

            if(currSizes[currDir - 1] > maxSize){
                for(int mexido : alterados){
                    currSizes[mexido] = originalSizes[mexido];
                }
                alterados.clear();
            }
        }
        for(int l = 0; l < numDiretorios; ++l){
            cout << currSizes[l] << ' ';
        }
        cout << '\n';
    }
}