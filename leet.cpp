#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int cash = 0;
         int hold = -prices[0];
         
         for(int i =0;i<prices.size();i++){
            int pre_cash = cash;
            cash = max(cash, hold+prices[i]);
            hold = max(hold, pre_cash - prices[i]);
         }
         return cash >= 0 ? cash : 0;
    }
};

int main(){

    return 0;
}
