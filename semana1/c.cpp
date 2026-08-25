#include<bits/stdc++.h>
using namespace std;

int main(){
    int total;
    cin >> total;
    vector<char> cores = {'R', 'O', 'Y', 'G', 'B', 'I', 'V'};

    int currIdx = 0;
    for(int i = 0; i < total; ++i){
        if(currIdx == 7) currIdx -= 4;
        cout << cores[currIdx];
        currIdx ++;
    }
}