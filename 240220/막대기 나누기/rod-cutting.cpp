#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 200

int n;
int value[MAX];
int dp[MAX];


int main() {
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> value[i];
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int curLength = j;
            int curValue = value[j];

            if(i-curLength < 0){
                continue;
            }

            dp[i] = max(dp[i], dp[i-curLength] + curValue);
            // cout << "i: " << i << " dp[i]: " << dp[i];
            // cout << " curLength: " << curLength << " curValue: " << curValue << "\n";
        }
    }

    cout << dp[n] << "\n";

    return 0;
}