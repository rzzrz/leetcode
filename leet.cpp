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
    using ll = long long;

    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        // 首先通过chars和vals整理一个各个字母对应的价值
        // 之后使用最大子数组和来计算最大开销，dp
        vector<int> map(26);
        // 首先默认所有字母都不在chars中
        for(int i = 0;i <26;i++){
            map[i] = i+1;
        }
        // 使用chars对map更新
        int i = 0;
        for(char c : chars){
            map[c - 'a'] = vals[i++]; 
        }
        // 动态规划阶段
        int len = s.size();
        vector<int> dp(len + 1,0);
        for(int i = 1;i <= len;i++){
            dp[i] = max(dp[i - 1] + map[s[i-1] - 'a'],map[s[i-1] - 'a']);
        }
        return *max_element(dp.begin(),dp.end());
    }
};

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    string str = "hghhghgghh";
    string chars = "hg";
    vector<int> vals = {2,3};
    std::cout<<s.maximumCostSubstring(str, chars,vals);
    std::cout<<"endl"<<endl;
    return 0;
}
