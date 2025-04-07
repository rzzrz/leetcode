#include<vector>
#include<string>
#include<algorithm>
#include<iostream>

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
    int deleteAndEarn(vector<int>& nums) {
        //对nums进行处理像打家劫舍一样
        std::sort(nums.begin(),nums.end());
        vector<int> rob;
        for(int i = 0;i<nums.size() - 1;i++){
            int now_num = nums[i];//当前的数字是几
            //这里有可能溢出注意(判断后面的是不是应该加个0)
            if(now_num != nums[i+1] && (now_num + 1) != nums[i+1])
            {
                rob.emplace_back(nums[i]);
                rob.emplace_back(0);
            }else{
                rob.emplace_back(nums[i]);
            }
        }
        rob.emplace_back(*nums.rbegin());
        // for(int i = 0;i<rob.size();i++)
        //     std::cout<<rob[i]<<' ';
        vector<int> new_rob;
        //将相邻的同种数字相加
        int now_num = rob[0];
        int now_times = 0;
        for(int i = 0;i < rob.size();i++){
            if(now_num != rob[i]){
                new_rob.emplace_back(now_num * now_times);
                now_num = rob[i];
                now_times = 1;
            }else{
                now_times++;
            }
        }
        new_rob.emplace_back(now_num * now_times);
        new_rob.emplace_back(0);

        for(int num:new_rob)
            std::cout<<num<<' ';

        int len = new_rob.size();
        vector<int> dp(len + 2,0);
        for(int i = 2;i<=len+1;i++){
            dp[i] = max(dp[i-1],new_rob[i-2]+dp[i-2]);
        }
        return *dp.rbegin();
    }
};

int main(){
    vector<int> nums = {2,4,3};
    Solution s;
    s.deleteAndEarn(nums);
    return 0;
}
