#include <cstdint>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<stack>
#include<limits>

using namespace std;

/*
    首先我们看到元素是可以重复选择的且选择循序不一样要算做不同的组合
    可以这样，设置一个长度为target的dp数组这样的，然后从头开始遍历
    所给的数组，我们要计算能够总数为i的组合都是什么
    e.g. :输入：nums = [1,2,3], target = 4
输出：7
解释：
所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
请注意，顺序不同的序列被视作不同的组合。、
    dp : 1 2 3 4
         0 0 0 0
    这时候就是什么开始计算
    然后我们对第一个nums元素1计算
    一可以到达1 那么dp[i] + 1
    1也可以是组成2的元素所以dp[2] + 1
    同理
    dp : 1 2 3 4
         1 1 1 1
         1 2 2 2
         1 2 3 3
*/
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        //定义状态:dp[i]表示长度为i的字符串组成的这和个数
        //状态装一dp[i]一定是由直接zero或者one组成
        //再就是字符串通过zero和one组合而成的
        const unsigned long long yushu = 1e9 + 7;
        vector<unsigned long long> dp(high+1,0);
        dp[0] = 1;
        for(int i = 1;i<=high; i++){
            if(zero <= i)
                dp[i] = (dp[i]+dp[i - zero])%yushu;
            if(one <= i)
                dp[i] = (dp[i] + dp[i - one])%yushu;
        }
        unsigned long long res = 0;
        for(int i = low;i<=high ;i++){
            res = (res + dp[i]) % yushu;
        }
        return res;
    }
};

int main(){
    vector<int> heigt = {1,8,6,2,5,4,8,3,7};
    Solution s;
    
    return 0;
}
