#include <bits/stdc++.h>
// #include <fmt>
using namespace std;


class Solution {
public:
    string decodeAtIndex(string s, int k) {
        vector<char> L;
        deque<int> length_deque;
        int length = 0;

        length_deque.emplace_back(0);

        for (auto x : s) {
            if (isalpha(x)) {
                L.emplace_back(x);
                ++length;
                length_deque.push_back(length);
            } else if (isdigit(x)) {
                int n = x-'0';
                length = length * n;
                length_deque.push_back(length);
                for (int i = 0; i < n-1; ++i) {
                    
                    L.emplace_back();
                }
                
            } else throw "NotImplemented";
        }

        for (auto x : length_deque) {
            cout << x << ", ";
        }
        cout << endl;

        string res(L.begin(), L.end());
        return res;
    }
};


int main(int arvc, char** argv){
    Solution S;
    string s(argv[1]);
    int k = stoi(argv[2]);
    auto res = S.decodeAtIndex(s, k);
    cout << res << endl;
    return 0;
}
