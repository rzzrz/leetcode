#include <utility>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
  int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
    // 创建队列模拟bfs
    std::queue<std::pair<int, int>> q;

    int n = maze.size();
    int m = maze[0].size();

    std::vector<std::vector<int>> dis(n,vector<int>(m,0));

    // 遵从上下左右
    int x[4] = {-1, +1, 0, 0};
    int y[4] = {0, 0, -1, +1};

    maze[entrance[0]][entrance[1]] = '+';
    q.push({entrance[0], entrance[1]});

    bool first_enter = false;

    while (!q.empty()) {
      std::pair<int, int> pos = q.front();
      q.pop();

      if ((pos.first == 0 || pos.first == n - 1 || pos.second == 0 ||
          pos.second == m - 1) && first_enter)
        return dis[pos.first][pos.second];

      for (int i = 0; i < 4; i++) {
        int dx = pos.first + x[i];
        int dy = pos.second + y[i];
        if (dx >= 0 && dy >= 0 && dx < n && dy < m && maze[dx][dy] == '.') {
          maze[dx][dy] = '+';
          dis[dx][dy] = dis[pos.first][pos.second] + 1;
          q.push({dx,dy});
        }
      }
      first_enter = true;
    }
    return -1;
  }
  
};

int main() {
  vector<int> nums = {1,1,1,1,1};

  Solution s;
  std::cout << s.findTargetSumWays(nums,3);
  std::cout << "endl" << endl;
  return 0;
}
