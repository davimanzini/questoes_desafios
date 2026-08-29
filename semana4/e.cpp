#include<bits/stdc++.h>
using namespace std;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    long long total;
    cin >> total;

    for(int i = 0; i < total; ++i){
        vector<long long> nums(3);
        cin >> nums[0] >> nums[1] >> nums[2];
        sort(nums.begin(), nums.end());
        long long acoes;
        cin >> acoes;

        long long diff1 = nums[1] - nums[0];
        if(acoes >= diff1){
            nums[0] += diff1;
            acoes -= diff1;
        }
        else{
            nums[0] += acoes;
            cout << nums[0] * nums[1] * nums[2] << '\n';
            continue;
        }

        long long diff2 = nums[2] - nums[1];

        if(acoes >= (2 * diff2)){
            nums[0] += diff2;
            nums[1] += diff2;
            acoes -= (2 * diff2);
        }
        else{
            long long metade = acoes / 2;
            nums[0] += metade;
            if(acoes % 2 == 0) nums[1] += metade;
            else nums[1] += metade + 1;
            cout << nums[0] * nums[1] * nums[2] << '\n';
            continue;
        }

   
        long long divPor3 = acoes / 3;
        nums[0] += divPor3;
        nums[1] += divPor3;
        nums[2] += divPor3;
       
        int resto = acoes % 3;
        if(resto == 2){
            nums[0]++;
            nums[1]++;
        }
        else if(resto == 1){
            nums[0]++;
        }
        
        long long produto = nums[0] * nums[1] * nums[2];
        cout << produto << '\n';
    }
}