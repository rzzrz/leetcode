#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<stack>

using namespace std;

/*
    首先爬楼梯的话 将子问题拆分成一个一个小问题
    首先爬上第一节楼梯的话就之后选择一步他上去
    到了第二节的话就是step一次从第一个阶梯他上来的 dp[0] = 1
    或者一次迈了两个台阶那就是由  dp[1] = dp[1 - 1] 
    第三个台阶的话就是从第一个台阶迈上两格直接上来的或者从第二个台阶
    dp[2] = dp[2 - 1] + dp[2 - 2]
*/
class Solution {
    public:
        int climbStairs(int n) {
            vector<int> dp(n + 1,0);
            dp[0] = 1;
            dp[1] = 1;
            for(int i = 2;i < n;i++){                
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            return dp[n];
        }
    };

int main(){
    vector<int> heigt = {1,8,6,2,5,4,8,3,7};
    Solution s;
    
    return 0;
}
