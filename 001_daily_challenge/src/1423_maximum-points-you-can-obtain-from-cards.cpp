#include <bits/stdc++.h>
// #include <fmt>
using namespace std;


class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int L = cardPoints.size();
        int tmp = 0;
        for (int i = k; i > 0; --i) {
            tmp += cardPoints[L - i];
        }
        int res = tmp;

        for (int i = k; i > 0; --i) {
            tmp -= cardPoints[L - i];
            tmp += cardPoints[k-i];
            if (tmp > res) {
                res = tmp;
            }
        }

        return res;
        
    }
};


int main(int arvc, char** argv){
    Solution S;
    vector<int> cardPoints = {1,2,3,4,5,6,1};
    int k = 3;
    auto res = S.maxScore(cardPoints, k);
    cout << res << endl;
    return 0;
}
