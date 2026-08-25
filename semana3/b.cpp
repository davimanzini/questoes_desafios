#include<bits/stdc++.h>
using namespace std;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string num;
    cin >> num;
    int n = num.length();
    int espacos = n - 1;

    long long somaTotal = 0;
    int maxMascara = 1 << espacos;

    for(int mascara = 0; mascara < maxMascara; ++ mascara){

        long long currNum = 0;
        long long sum = 0;

        for(int i = 0; i < n; ++i){
            currNum = currNum * 10 + (num[i] - '0');

            if(i < n - 1 && (mascara & (1 << i))){
                sum += currNum;
                currNum = 0;
            }
        }
        sum += currNum;
        somaTotal += sum;
    }
    cout << somaTotal << '\n';
}