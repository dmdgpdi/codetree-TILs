#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1000

int weight[MAX];
int value[MAX];
int totalWeight;
int n;
int dp[MAX][MAX];

int main() {
    cin >> n >> totalWeight;

    for(int i=1; i<=n; i++){
        cin >> weight[i] >> value[i];
    }

    for(int i=1; i<=n; i++){
        int curValue = value[i];
        int curWeight = weight[i];

        for(int j=1; j<=totalWeight; j++){
            if(j<curWeight){
                dp[i][j] = dp[i][j-1];
            }else if(curWeight <= j){
                int repeatCount = j/curWeight;
                int curMax = 0;

                for(int k=1; k<=repeatCount; k++){
                    curMax = max(dp[i-1][j-curWeight*k] + curValue*k, curMax);
                }

                dp[i][j] = max(curMax,dp[i-1][j]);
            }
        }
    }

    cout << dp[n][totalWeight];
    return 0;
}