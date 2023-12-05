#include <string>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool digitCount(std::string num) {
        std::unordered_map<int, int> h;
        int n = num.size();
        for (int i = 0; i < n; i++) {
            int digit = num[i] - '0';
            h[num[i] - '0']++;
        }
        for (int i = 0; i < n; i++) {
            int v = num[i] - '0';
            if (h[i] != v) {
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    std::string num = "1210";
    bool res = s.digitCount(num);
    std::cout << res << std::endl;
    return 0;
}
