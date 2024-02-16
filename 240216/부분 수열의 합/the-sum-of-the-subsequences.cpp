#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define MAX 10005

int n,m;
int dp[MAX];
int num[MAX];



int main() {
    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> num[i];
    }


    dp[0] = 1;

    for(int i=0; i<n; i++){
        for(int j=m; 0<j; j--){
            if(0 <= j-num[i] && dp[j-num[i]] != 0){
                dp[j] = 1;
                // cout << num[i] << " 일 때: " << j << " 에 값 넣음 => " << dp[j] << " \n";
            }
        }
    }

    string ans = 0 < dp[m] ? "Yes" : "No";
    cout << ans << "\n";

    return 0;
}