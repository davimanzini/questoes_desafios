#include<bits/stdc++.h>
using namespace std;

int main(){
    int numElements;
    cin >> numElements;
    if(numElements == 1){
        cout << 0 << '\n';
        return 0;
    } 
    vector<int> prazeres;

    for(int k = 0; k < numElements; ++k){
        int num;
        cin >> num;
        prazeres.push_back(num);
    }

    long long ans = 0;
    int i = 0;
    int j = i + 1;
    
    while(j < numElements){
        if(prazeres[i] > prazeres[j]){
            long long add = prazeres[i] - prazeres[j];
            prazeres[j] += add;
            ans += add;
        }
        i = j;
        j++;
    }
    cout << ans << '\n';
}