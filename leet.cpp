#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int findCircleNum(vector<vector<int>> &isConnected) {
    // 并查集使用
    int citicies = isConnected.size();
    vector<int> parent(citicies);
    for (int i = 0; i < citicies; i++)
      parent[i] = i;

    for (int i = 0; i < citicies; i++) {
      for (int j = i + 1; j < citicies; j++) {
        if (isConnected[i][j])
          union_set(parent, i, j);
      }
    }
    int province = 0;
    for (int i = 0; i < citicies; i++) {
      if (parent[i] == i)
        province++;
    }
    return province;
  }

private:
  int find(vector<int> &parent, int index) {
    if (parent[index] != index)
      parent[index] = find(parent, parent[index]);
    return parent[index];
  }
  bool union_set(vector<int> &parent, int a, int b) {
    int roota = find(parent, a);
    int rootb = find(parent, b);
    if (roota == rootb)
      return false; // 在一个集合，不合并
    parent[roota] = parent[b];
    return true; // 合并在一起了
  }
};

int main() {
  Solution s;
  std::vector<int> nums = {7, 12, 9, 8, 9, 15};
  std::cout << s.findKOr(nums,4);
  return 0;
}