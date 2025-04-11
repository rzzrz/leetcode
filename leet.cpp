#include <climits>
#include <cstddef>
#include <memory>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
  int uniquePaths(int m, int n) {
    // 进行二维dp就可以
    // 状态定义dp[i][j] 表示机器人走i,j位置的路径数
    // 状态转移方程
    // dp[i][j] = dp[i-1][j] + dp[i][j-1];
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[1][0] = 1;
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[m][n];
  }

// private:
//   int dfs(int i ,int j) {
//     if ()
//       return 1;
//     return dfs(i-1,j)+dfs(i,j-1);
//   }
};

int main(){
  vector<int> nums = {-3, -5, -3, -2, -6, 3, 10, -10, -8, -3,
                      0,  10, 3,  -5, 8,  7, -9, -9,  5,  -8};

  Solution s;
  std::cout << s.maxAbsoluteSum(nums); 
  std::cout << "endl" << endl;
  return 0;
}
