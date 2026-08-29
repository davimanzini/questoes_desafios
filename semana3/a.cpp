#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    long cadeia;
    cin >> cadeia;
    long maior = 0;
    long menor = 0;
    int count = 0;
    vector<long> nums;

    while(cadeia > 0){
        long curr = cadeia % 10;
        nums.push_back(curr);
        cadeia /= 10;
    }

    sort(nums.begin(), nums.end());

    int n = nums.size();
    for(int i = n - 1; i >= 0; --i){
        long curr = nums[i];
        if(i == n - 1){
            maior += curr;
        }
        else if(i == n - 2){
            menor += curr;
        }
        else{
            if(maior >= menor){
                menor = (menor * 10) + curr;
            }
            else{
                maior = (maior * 10) + curr;
            }
            count++;
        }
    }
    long ans = maior * menor;
    cout << ans << '\n';
}