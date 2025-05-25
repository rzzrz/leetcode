#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    memroy.push_back(0);
    dfs(graph, 0);
    return ret;
  }

  void dfs(vector<vector<int>> &graph, int node) {
    if ((graph.size() - 1)) {
      ret.emplace_back(memroy);
      return;
    }
    for (int i = 0; i < graph[node].size(); ++i) {
      memroy.push_back(graph[node][i]);
      dfs(graph, graph[node][i]);
      memroy.pop_back();
    }
    return;
  }
private:
vector<int> memroy;
vector<vector<int>> ret;
};

int main() {
  Solution s;
  std::vector<std::vector<int>> edge = {{0,1},{1,2},{2,0}};
  std::cout << s.validPath(3,edge , 0, 2);
  return 0;
}