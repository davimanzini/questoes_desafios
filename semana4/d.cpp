#include<bits/stdc++.h>
using namespace std;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, a;

    while(cin >> n >> a){
        if(n == 0 && a == 0){
            break;
        }

        double countTotal = 0;
        vector<int> tamanhos(10001, 0);
        for(int i = 0; i < n; ++i){
            int tiraAtual;
            cin >> tiraAtual;
            countTotal += tiraAtual;
            tamanhos[tiraAtual]++;
        }
        
        int alturaCorte = 1;
        int restantes = n;
        bool resolvido = false;

        while(countTotal > a){
            restantes -= tamanhos[alturaCorte - 1];

            if(countTotal - restantes < a){
                double altura = alturaCorte - 1 + double(countTotal - a) / restantes;
                cout << fixed << setprecision(4) << altura << '\n';
                resolvido = true;
                break;
            }
            countTotal -= restantes;
            alturaCorte++;
        }
        if(!resolvido){
            if(countTotal == a){
                if(alturaCorte == 1){
                    cout << ":D" << '\n';
                }
                else{
                    cout << fixed << setprecision(4) << double(alturaCorte - 1) << '\n';
                }
            }
            else cout << "-.-" << '\n';
        }
        
    }
}