#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    static constexpr int T = 243, N = 5, M = 6;
    int n, m, tot;
    int p[N];
    int d[N * N][T][M + 1][M + 1];

    // 邻居间的分数
    static constexpr int score[3][3] = {
        {0, 0, 0},
        {0, -60, -10},
        {0, -10, 40}
    };

public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        this->n = n;
        this->m = m;
        // 状态总数为 3^n
        this->tot = pow(3, n);
        p[0] = 1;
        for (int i = 1; i < n; i++) {
            p[i] = p[i - 1] * 3;
        }
        
        // 记忆化搜索数组，初始化为 -1，表示未赋值
        memset(d, -1, sizeof d);
        return dfs(0, 0, introvertsCount, extrovertsCount);
    }

    int dfs(int pos, int mask, int iv, int ev) {
        if (pos == n * m || (iv == 0 && ev == 0)) {
            return 0;
        }
        int& res = d[pos][mask][iv][ev];
        if (res != -1) {
            return res;
        }
        res = 0;
        int up = mask / p[n - 1], left = mask % 3;
        // 若处于第一列，则左侧没有元素，将 left 置为 0
        if (pos % n == 0) {
            left = 0;
        }
        for (int i = 0; i < 3; i++) {
            if ((i == 1 && iv == 0) || (i == 2 && ev == 0)) {
                continue;
            }
            int next_mask = mask % p[n - 1] * 3 + i;
            int score_sum = dfs(pos + 1, next_mask, iv - (i == 1), ev - (i == 2))
                            + score[up][i]
                            + score[left][i];
            if (i == 1) {
                score_sum += 120;
            } else if (i == 2) {
                score_sum += 40;
            }
            res = max(res, score_sum);
        }
        return res;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode.cn/problems/maximize-grid-happiness/solution/zui-da-hua-wang-ge-xing-fu-gan-by-leetco-0flf/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int main(int argc, char **argv){
    if (argc != 5){
        cout << "[Error] need 5 parameters !" << endl;
        exit(0);
    } 
    int m = stoi(argv[1]);
    int n = stoi(argv[2]);
    int iv = stoi(argv[3]);
    int ev = stoi(argv[4]);
    Solution S;

    auto res = S.getMaxGridHappiness(m, n, iv, ev);
    cout << res << endl;

    return 0;
}
