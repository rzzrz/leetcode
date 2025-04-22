#include <utility>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
  int maxDistance(vector<vector<int>> &grid) {
    // 从每个陆地向海洋扩散 返回的事曼哈顿距离所以bfs的距离就是返回值
    // 设立一个距离数组 在更新数组的时候要 要烤炉上一次的值
    // 保留这次更新和上次更新中最小的值

    std::queue<pair<int, int>> q;

    // 方向数组
    int dx[4] = {-1, +1, 0, 0};
    int dy[4] = {0,0,-1,+1};

    int n = grid.size();
    // 记录距离
    std::vector<std::vector<int>> vec(n, vector<int>(n, -1));
    // 网格副本
    std::vector<std::vector<int>> cp = grid;
    auto reset = [&grid, &cp]() { cp = grid; };

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j]) {
          reset(); // 恢复副本
          q.push({i, j});

          while (!q.empty()) {
            std::pair<int, int> pos = q.front();
            q.pop();

            for (int u = 0; u < 4; u++) {
              int x = pos.first + dx[u];
              int y = pos.second + dy[u];
              if (x >= 0 && x < n && y >= 0 && y < n && cp[x][y] == 0) {
                q.push({x, y});
                cp[x][y] = 1;                // 更新距离

                vec[x][y] = vec[x][y] == -1 ? vec[pos.first][pos.second] + 1 :
                                            min(vec[x][y],vec[pos.first][pos.second] + 1);
              }
            }
          }
        }
      }
    }
    int res = -1;
    for (std::vector<int> &nums : vec) {
      for (int num : nums)
        res = max(res, num);
    }
    return res == -1?-1:++res;
  }
};

int main() {
  vector<int> nums = {1,1,1,1,1};

  Solution s;
  //std::cout << s.findTargetSumWays(nums,3);
  //std::cout << "endl" << endl;
  return 0;
}
