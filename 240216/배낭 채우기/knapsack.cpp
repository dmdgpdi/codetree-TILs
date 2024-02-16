#include <iostream>

using namespace std;

#define MAX 10004

int n,m;

int dp[MAX][MAX];
int jewel[MAX];
int weight[MAX];

int main() {
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        cin >> weight[i] >> jewel[i];
    }



    for(int i=1; i<=n; i++){
        int curWeight = weight[i];
        int curValue = jewel[i];

        for(int j=1; j<=m; j++){
            int prevMax = max(dp[i-1][j],dp[i][j-1]);

            // cout << "i:" << i << " j:" << j << " " << "curW: " << curWeight;
            // cout << " curV: " << curValue << " prevM: " << prevMax << "\n";

            if(j < curWeight){
                dp[i][j] = prevMax;
                // cout << "이전 값 적용!\n";
            }else if(curWeight<=j){
                dp[i][j] = max(prevMax, dp[i-1][j-curWeight]+curValue);
            }


            // cout << "dp: " << dp[i][j] << "\n";


        }
    }

    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=m; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << dp[n][m] << "\n";


    return 0;
}