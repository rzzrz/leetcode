#include <utility>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    int dx[4] = {-1, +1, 0, 0};
    int dy[4] = {0, 0, -1, +1};

    std::queue<pair<int, int>> q;

    int vec[10][10];
    for (int i = 0; i < 10; i++)
      for (int j = 0; j < 10; j++)
        vec[i][j] = 0;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 2)
          q.push({i, j});
      }

    int times = 0;
    
    while (!q.empty()) {
      pair<int, int> pos = q.front();
      q.pop();

      for (int u = 0; u < 4; u++) {
        int x = dx[u] + pos.first;
        int y = dy[u] + pos.second;

        if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1) {
          grid[x][y] = 2;
          q.push({x, y});
          vec[x][y] = vec[pos.first][pos.second] + 1;
          times = max(times, vec[x][y]);
        }
        
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1)
          return -1;
      }
    }

    return times;
  }
};


int main() {
  vector<int> nums = {1,1,1,1,1};

  Solution s;
  //std::cout << s.findTargetSumWays(nums,3);
  //std::cout << "endl" << endl;
  return 0;
}
