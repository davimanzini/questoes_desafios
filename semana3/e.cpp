#include<bits/stdc++.h>
using namespace std;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int testes;
    cin >> testes;

    for(int i = 0; i < testes; ++i){
        vector<int> nums(3, 0);
        cin >> nums[0] >> nums[1] >> nums[2];
        for(int j = 0; j < 5; ++j){
            sort(nums.begin(), nums.end());
            nums[0] += 1;
        }
        int ans = nums[0] * nums[1] * nums[2];
        cout << ans << '\n';
    }
}