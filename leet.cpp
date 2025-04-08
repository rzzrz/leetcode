#include<vector>
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;


class Solution {
public:
    int countHousePlacements(int n) {
        // 根据题目要求我们发现街道两侧的房子放置情况不会不想影响，
        // 且满足乘法原理随意我们只需要计算一侧的可能的次数以后
        // 根据乘法原理乘以自己就可以了
        // 我们将问题简化就变成了打家劫舍问题
        // 我们定义dp[i]为到当前i地块有多少种组合方式
        // 根据递归的界限发现取值范围是 -2 -1 0 ... n-1 共n + 2元素
        using ll = long long;
        vector<ll> dp(n + 2,0);
        const ll MOD = 1e9 + 7;
        //
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2; i<= n+1; i++){
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
            // dp[i - 1] 和 dp[i - 2]表示了
            // 当前i地痞没有被选择所以我们选择加上他上一个地皮的组合数目
            // 和当前I地皮被选择了这时候就隐含了他的上一块地皮没有被选择
            // 所以我们这个语句就已经表示了当前地皮有没有被选择的含义
        }
        return (dp[n] * dp[n]) % MOD;
    }
private:
    // 对于选择当前地痞建房子的话那么就意味着 
    // int dfs(int i){
    //     if(i<0)
    //         return 1;
    //     return dfs(i - 1) + dfs(i - 2);
    // }
};

int main(){
    Solution s;
    std::cout<<s.countHousePlacements(3);

    return 0;
}
