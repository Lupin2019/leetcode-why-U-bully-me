#include <bits/stdc++.h>
// #include <fmt>
using namespace std;


class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001);
        for (auto &trip : trips) {
            diff[trip[1]] += trip[0];
            diff[trip[2]] -= trip[0];
        }

        int count = 0;
        for (int i = 0; i < 1001; ++i) {
            count += diff[i];
            if (count > capacity) return false;
        }
        return true;
    }
};


int main(int arvc, char** argv){
    Solution S;
    vector<vector<int>> trips = {{2, 1, 5}, {3, 3, 7}};
    int capacity = 4;
    auto res = S.carPooling(trips, capacity);
    cout << res << endl;
    return 0;
}
