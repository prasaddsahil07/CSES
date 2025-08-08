// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// ll solve(vector<ll>& nums, int i, int j, int player, vector<vector<vector<ll>>>& dp){
//     if(i > j){
//         return 0;
//     }
//     if(dp[i][j][player] != -1){
//         return dp[i][j][player];
//     }

//     // for player 0, we want to maximize the score
//     // for player 1, we want to minimize the score
//     ll score = (player == 0)? -10e17: 10e17;

//     if(player == 0){
//         ll firstPick = nums[i] + solve(nums, i+1, j, 1, dp);
//         ll lastPick = nums[j] + solve(nums, i, j-1, 1, dp);
//         score = max({score, firstPick, lastPick});
//     }
//     else{
//         ll firstPick = solve(nums, i+1, j, 0, dp);
//         ll lastPick = solve(nums, i, j-1, 0, dp);
//         score = min({score, firstPick, lastPick});
//     }
//     return dp[i][j][player] = score;
// }

// int main(){
//     int n;
//     cin>>n;
//     vector<ll> vec(n);
//     for(auto& v: vec){
//         cin>>v;
//     } 

//     // dp[i][j][player] will store the maximum score for the player starting at index i to j
//     vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
//     cout<<solve(vec, 0, n-1, 0, dp)<<endl;
// }






#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(vector<ll>& nums) {
    int n = nums.size();
    // dp[i][j] will store the maximum score the first player can achieve with subarray nums[i..j]
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    
    // Base case: when there is only one element, the first player picks that element.
    for (int i = 0; i < n; ++i) {
        dp[i][i] = nums[i];
    }

    // Fill the table for all subarray lengths > 1
    for (int length = 2; length <= n; ++length) {
        for (int i = 0; i <= n - length; ++i) {
            int j = i + length - 1; // End of the subarray

            // If player 1 picks nums[i], the remaining range is nums[i+1..j], and player 2 plays optimally
            ll pickFirst = nums[i] + min((i+2 <= j)? dp[i+2][j]: 0, (i+1 <= j-1)? dp[i+1][j-1]: 0);

            // If player 1 picks nums[j], the remaining range is nums[i..j-1], and player 2 plays optimally
            ll pickLast = nums[j] + min((i <= j-2) ? dp[i][j-2]: 0, (i+1 <= j-1)? dp[i+1][j-1]: 0);

            // The first player will choose the option that maximizes their score
            dp[i][j] = max(pickFirst, pickLast);
        }
    }

    // The result for the entire array is stored in dp[0][n-1]
    return dp[0][n-1];
}

int main() {
    int n;
    cin >> n;
    vector<ll> vec(n);
    for(auto& v: vec){
        cin>>v;
    } 
    cout<<solve(vec)<<endl;
}