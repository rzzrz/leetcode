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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            if(list1 == nullptr)
                return list2;
            if(list2 == nullptr)
                return list1;
            if(list1->val<list2->val){
                list1->next = mergeTwoLists(list1->next,list2);
                return list1;
            }else{
                list2->next = mergeTwoLists(list1,list2->next);
                return list2;
            }
        }
    };

int main(){
    vector<int> nums = {2,4,3};
    Solution s;
    s.deleteAndEarn(nums);
    return 0;
}
