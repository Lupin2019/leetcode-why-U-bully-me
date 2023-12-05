#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<bool> occured(maxVal + 1, false);
        for (int num : nums) {
            occured[num] = true;
        }
        int ans = 0;
        for (int i = 1; i <= maxVal; i++) {
            int subGcd = 0;
            for (int j = i; j <= maxVal; j += i) {
                if (occured[j]) {
                    if (subGcd == 0) {
                        subGcd = j;
                    } else {
                        subGcd = __gcd(subGcd, j);
                    }
                    if (subGcd == i) {
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};


int main(){
    vector<int> nums = {5,15,40,5,6};
    Solution solution;
    int res;
    res = solution.countDifferentSubsequenceGCDs(nums);
    cout << res << endl;
    return 0;
}


