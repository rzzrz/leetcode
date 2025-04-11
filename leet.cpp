#include <climits>
#include <cstddef>
#include <memory>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
  bool canPartition(vector<int> &nums) {
    // 统计数字总和之后除以二这样就变成了0 - 1背包问题
    // 之后使用动态规划进行查找数组中是否有能组成满足
    // 把背包装满的组合
    // 状态转移方程还 dp[j] = max(dp[j],dp[j - nums[i]] + nums[i])

    int total = 0;
    for (int num : nums)
      total += num;
    if (total % 2)//奇数
      return false;
    int target = total / 2;
    int len = nums.size();

    vector<int> dp(target + 1, 0);
    for (int i = 0; i < len; i++) {//物品
      for (int j = target; j >= nums[i]; j--) {//dp数组
        dp[j] = max(dp[j],dp[j-nums[i]] + nums[i]);
      }
    }
    return dp[target] == target;
  }
};

int main(){
  vector<int> nums = {-3, -5, -3, -2, -6, 3, 10, -10, -8, -3,
                      0,  10, 3,  -5, 8,  7, -9, -9,  5,  -8};

  Solution s;
  std::cout << s.maxAbsoluteSum(nums); 
  std::cout << "endl" << endl;
  return 0;
}
