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
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    // obstacleGrid.insert(obstacleGrid.begin(), vector<int>(n, 0));
    // for (vector<int> &vec : obstacleGrid) {
    //   vec.insert(vec.begin(),0);
    // }

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[1][0] = 1;
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (!obstacleGrid[i-1][j-1])
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[m][n];
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
