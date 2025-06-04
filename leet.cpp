#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdint>
#include <functional>
#include <iostream>
#include <iterator>
#include <mutex>
#include <queue>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges,
                                       vector<vector<int>> &blueEdges) {
    // 首先bfs 在 bfs的过程中要使用pair表明，他是从红线过来的
    // 还是从蓝线过来的
    enum color { red = 0, blue = 1 };

    // [red,blue]
    // [red,blue]
    // ...  ...
    // 该数组表明 从red/blue进来的当前节点被访问过了
    vector<vector<bool>> visited(n, vector<bool>(2, false));

    // 表示从color路径过来到的节点
    queue<pair<int, color>> q;

    std::vector<int> res(n, -1);
    res[0] = 0;

    // 当前的路径长度
    int dis = 0;
    q.push({0, red});
    q.push({0, blue});

    while (!q.empty()) {
      int count_queue = q.size();
      for (int i = 0; i < count_queue; ++i) {
        auto now_node = q.front();
        q.pop();
        if (now_node.second == red) {
          // 从红色路径来的 要找蓝色路径
          for (auto path : blueEdges) {
            int u = path[0];
            int v = path[1];
            if (u == now_node.first && !visited[v][blue]) {
              q.push({v, blue});
              visited[v][blue] = true;
              res[v] =
                  -1 == res[v] ? dis + 1 : min(res[v], dis + 1);
            }
          }
        } else {
          for (auto path : redEdges) {
            int u = path[0];
            int v = path[1];
            if (u == now_node.first && !visited[v][red]) {
              q.push({v, red});
              visited[v][red] = true;
              res[v] = -1 == res[v] ? dis + 1 : min(res[v], dis + 1);
            }
          }
        }
      }
      dis ++;
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<vector<int>> redEdges = {{0, 1}, {1, 2}};
  vector<vector<int>> blueEdges;
  s.shortestAlternatingPaths(3, redEdges, blueEdges);
  return 0;
}