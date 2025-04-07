#include <cstdint>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<stack>
#include<limits>

using namespace std;

/*
    每个阶梯都是有消耗的，可以从顶部楼梯开始像低端楼梯过度，
    因为下面的楼梯在选择上面的楼梯肯定是要能到达楼梯且要费用最小的
    首先给想的数组是每个台阶的费用也就是在这个台阶上去要花多少钱
    那么也就是说顶层是没有台阶费用的所以就是数组长度就是处了顶层的长度
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        vector<int> dp(len + 1,INT32_MAX);
        // 表示到达i位置(顶层或者楼梯)到达顶层要花最少钱
        dp[len] = 0;
        dp[len - 1] = cost[len - 1];
        for(int i = len - 2;i>=0;i--){
            dp[i] = cost[i] + min(dp[i + 1],dp[i + 2]);
        }  
        return min(dp[0],dp[1]);
   }
};

int main(){
    vector<int> heigt = {1,8,6,2,5,4,8,3,7};
    Solution s;
    
    return 0;
}
