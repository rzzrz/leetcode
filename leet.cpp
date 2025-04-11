#include <algorithm>
#include <climits>
#include <cstddef>
#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    dfs(nums, target, 0, nums.size() - 1);
    return res;
  }

private:
  int res = 0;
  void dfs(vector<int> &nums, int target, int tmp, int i) {
    if (i < 0) {
      if (tmp == target)
        res++;
      return;
    }
      

    dfs(nums, target, tmp + nums[i], i - 1);
    dfs(nums, target, tmp - nums[i], i - 1);
  }
};

int main() {
  vector<int> nums = {1,1,1,1,1};

  Solution s;
  std::cout << s.findTargetSumWays(nums,3);
  std::cout << "endl" << endl;
  return 0;
}
