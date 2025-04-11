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
  int minPathSum(vector<vector<int>> &grid) {
    // 首先做一个二维的dp
    // dp[i][j]就是到达当前位置时的最大值
    // 规则是当前这个节点一定是从他的上面或者他的左侧进入的
    // 所以状态方程就应该是从左侧或者上册进行选择最大值
    // dp[i][j] = min(dp[i-1][j],dp[i][j-1])
    int row = grid.size();
    int clow = grid[0].size();
    vector<vector<int>> dp(row + 1, vector<int>(clow + 1, 0));
    for (int i = 2; i <= row; i++) {
      dp[i][0] = INT_MAX;
    }
    for (int i = 2; i <= clow; i++) {
      dp[0][i] = INT_MAX;
    }
    
    for (int i = 1; i <= row; i++) {
      for (int j = 1; j <= clow; j++) {
        dp[i][j] = min(dp[i - 1][j] + grid[i - 1][j - 1],
                       dp[i][j - 1] + grid[i - 1][j - 1]);
      }
    }
    return dp[row][clow];
  }
};

int main(){
  vector<int> nums = {-3, -5, -3, -2, -6, 3, 10, -10, -8, -3,
                      0,  10, 3,  -5, 8,  7, -9, -9,  5,  -8};

  Solution s;
  std::cout << s.maxAbsoluteSum(nums); 
  std::cout << "endl" << endl;
  return 0;
}
