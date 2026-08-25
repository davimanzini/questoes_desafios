#include<bits/stdc++.h>
using namespace std;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    deque<pair<int, int>> animais;
    int total;
    cin >> total;

    for(int i = 0; i < total; ++i){
        int animal;
        cin >> animal;

        while(!animais.empty() && animais.back().first >= animal){
            animais.pop_back();
        }
        if(animais.empty()){
            cout << 0 << ' ';
        }
        else{
            cout << animais.back().second << ' ';
        }
        animais.push_back({animal, i + 1});
    }
}