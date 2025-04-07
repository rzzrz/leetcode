#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        using ll = long long;
        ll res =0;
        ll left = 0;
        ll right = height.size() - 1;
        while(left < right){
            res = max(res,(right - left) *min(height[left],height[right]));
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return res;
    }
};

int main(){
    vector<int> heigt = {1,8,6,2,5,4,8,3,7};
    Solution s;
    s.maxArea(heigt);
    return 0;
}
