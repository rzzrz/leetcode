#include<vector>
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(2,vector<int>(n+2,0));
        //
        for(int i = 2; i<=n+1;i++){
            dp[0][i] = max(dp[0][i - 1], nums[i-2] + dp[0][i - 2]);
        }
        for(int i = 3; i<=n+2;i++){
            dp[1][i] = max(dp[1][i - 1], nums[i-2] + dp[1][i - 2]);
        }
        return max(dp[0][n+1],dp[1][n+2]);
    }

private:
    // int dfs(int low,int n,vector<int>& nums){
    //     if(n<low)
    //         return 0;
    //     return max(dfs(low,n-1,nums),(nums[n] + dfs(low,n-2,nums)));
    // } 
};

int main(){
    vector<int> nums = {1,2,3,1};
    Solution s;
    std::cout<<s.rob(nums);

    return 0;
}
