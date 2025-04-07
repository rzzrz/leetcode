#include<vector>
#include<string>

using namespace std;

/*
    动态规划
    状态定义dp[i]对于第i个按键为止有多少个组合
    状态转换:首先要知道某个按键如果在dp下的话，只能和他后面的相同按键并且不能超出最大值
    进行组合，dp就应该等于上一轮没有自己的次数加上这次单独解析自己的次数，然后加上
    dp[i] 和 dp[i - 1]的组合然后最多进行到同种
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len + 2 ,0);

        for(int i = 2; i<=len + 1; i++){
            dp[i] = max(dp[i - 1],nums[i - 2] + dp[i - 2]);
        }
        return *dp.rbegin();
    }
// private:
//     int dfs(int i,vector<int>& nums){
//         if(i<0)
//             return 0;
//         return max(dfs(i-1,nums),dfs(i-2,nums)+nums[i]);
//     }
};

int main(){
    vector<int> heigt = {1,8,6,2,5,4,8,3,7};
    Solution s;
    
    return 0;
}
