#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
    public:
        vector<int> partitionLabels(string s) {
            // 将每个字符最后出现的位置记录下来，
            // 之后遍历看当前元素是不是最后有次出现，
            // 并且可以维护一个哈希表记录还没有因为
            // 最后一次出现消除的
            int last[26]{0};

            int n = s.size();
            for(int i = 0; i < n; ++i)
                last[s[i] - 'a'] = i;

            vector<int> res;
            int max_len = 0;
            int begin = 0;
            for(int i = 0;i < n; ++i){
                max_len = max(max_len , last[s[i] - 'a']);
                if(i == max_len){
                    res.push_back(i + 1 - begin);
                    begin = i + 1;
                }
                    
            }
            return res;
        }
    };

int main(){
    string str;
    cin >> str;
    Solution s;
    s.partitionLabels(str);
    return 0;
}
