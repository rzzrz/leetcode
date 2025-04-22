#include <utility>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      // 使用bfs进行便利 用一个数组维护当前传播距离
      int n = grid.size();
      std::vector<std::vector<int>> vec(n,vector<int>(n,1));
      std::queue<pair<int, int>> q;

      // 方向数组
      int dx[8] = {-1, -1, -1, 0, 0, +1, +1, +1};
      int dy[8] = {-1, 0, +1, -1, +1, -1, 0, +1};

      if (grid[0][0])
        return -1;

      q.push({0, 0});
      vec[0][0] = 1;
      
      while (!q.empty()) {
        pair<int, int> now_pos = q.front();
        q.pop();

        if (now_pos.first == n-1 && now_pos.second == n-1)
          return vec[now_pos.first][now_pos.second];

        for (int i = 0; i < 8; i++) {
          int x = now_pos.first + dx[i];
          int y = now_pos.second + dy[i];

          if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0) {
            grid[x][y] = 1;
            q.push({x, y});
            vec[x][y] = vec[now_pos.first][now_pos.second] + 1;
          }
        }
      }
      return -1;
    }
};

int main() {
  vector<int> nums = {1,1,1,1,1};

  Solution s;
  //std::cout << s.findTargetSumWays(nums,3);
  //std::cout << "endl" << endl;
  return 0;
}
