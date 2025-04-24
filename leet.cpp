#include <utility>
#include <vector>
#include <queue>

using namespace std;



class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {

    std::queue<pair<int, int>> q;

    // 方向数组
    int dx[4] = {-1, +1, 0, 0};
    int dy[4] = {0, 0, -1, +1};

    int n = mat.size();
    int m = mat[0].size();
    // 记录距离
    std::vector<std::vector<int>> vec(n, vector<int>(m, 0));
    // 网格副本
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!mat[i][j]) {
          q.push({i, j});
          mat[i][j] = -1;
        }
      }
    }
    while (!q.empty()) {
      std::pair<int, int> pos = q.front();
      q.pop();
      int x = pos.first;
      int y = pos.second;

      for (int u = 0; u < 4; u++) {
        int fx = x + dx[u];
        int fy = y + dy[u];

        if (fx >= 0 && fx < n && fy >= 0 && fy < m && mat[fx][fy] == 1) {
          q.push({fx, fy});
          mat[fx][fy] = -1;
          vec[fx][fy] = vec[x][y] + 1;
         }
      }
    }
    return vec;
  }
};

int main() {
  vector<int> nums = {1,1,1,1,1};

  Solution s;
  //std::cout << s.findTargetSumWays(nums,3);
  //std::cout << "endl" << endl;
  return 0;
}
