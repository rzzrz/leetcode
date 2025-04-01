#include<vector>
#include<string>
#include<iostream>

using namespace std;
// 递归时间复杂度太大了
// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         recurSubstring(0,0,0, text1, text2);
//         return res;
//     }
// private:
//     int res = 0;
//     void recurSubstring(int maxSubLen,int i,int j,string& str1,string& str2){
//         if(i>=str1.size()||j>=str2.size()){
//             res = max(res,maxSubLen);
//             return;
//         }

//         if(str1[i] == str2[j]){
//             recurSubstring(maxSubLen+1,i+1,j+1,str1, str2);
//         }else {
//             recurSubstring(maxSubLen,i+1,j,str1,str2);
//             recurSubstring(maxSubLen,i,j+1,str1,str2);
//         }
//     }
// };

// 优化一下使用动态规划
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        //根据状态转移方程
        for(int i = 1; i<=len1; i++){
            for(int j = 1; j <= len2; j++){
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[len1][len2];
    }
};
  
int main(){
    string str1;
    string str2;
    std::cin>>str1>>str2;
    Solution s;
    std::cout<<s.longestCommonSubsequence(str1,str2);
    return 0;
}