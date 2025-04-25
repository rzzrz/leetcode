#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
  vector<vector<int>> highestPeak(vector<vector<int>> &isWater) {
    // 这道题和01矩阵很相似
    // 把所有水域都加入队列中同步进行，然后进行高度增加

    std::queue<pair<int, int>> q;
    int m = isWater.size();
    int n = isWater[0].size();

    int dx[4] = {-1, +1, 0, 0};
    int dy[4] = {0,0,-1,+1};

    std::vector<std::vector<int>> height(m, std::vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (isWater[i][j]) {
          q.push({i, j});
          isWater[i][j] = -1;
        }
          
      }
    }

    while (!q.empty()) {
      std::pair<int, int> pos = q.front();
      q.pop();

      for (int u = 0; u < 4; u++) {
        int x = dx[u] + pos.first;
        int y = dy[u] + pos.second;

        if (x >= 0 && x < m && y >= 0 && y < n && isWater[x][y] == 0) {
          q.push({x, y});
          isWater[x][y] = -1;

          height[x][y] = height[pos.first][pos.second] + 1;
        }
      }
    }
    return height;
  }
};

int main() {
  vector<int> nums = {1,1,1,1,1};

  Solution s;
  //std::cout << s.findTargetSumWays(nums,3);
  //std::cout << "endl" << endl;
  return 0;
}
