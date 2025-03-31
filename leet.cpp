#include<vector>

using namespace std;
class Solution {
    public:
        int maxJump(vector<int>& stones) {
            int n = stones.size();
            int res = 0;
            if(n == 2)
                res = stones[1] - stones[2];
            for(int i = 2;i < n;i += 2){
                res = max(res,stones[i] - stones[i - 2]);
            }
            for(int i = 3;i < n;i += 2)
            {
                res = max(res,stones[i] - stones[i - 2]);
            }
            return res;
        }
    };
int main(){


    return 0;
}