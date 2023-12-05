#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumValue(vector<string>& strs) {
        bool has_number, has_letter;
        int max_value = 0;
        for (auto &s : strs){
            has_number = false;
            has_letter = false;
            for (auto &c : s){
                int x = c - '0';
                if (x >= 0 && x <= 9){
                    has_number = true;
                } else {
                    has_letter = true;
                }
            }
            // cout << "number: " << has_number << "; " 
            // << "letter: " << has_letter << endl;
            if (has_number && !has_letter){
                int tmp = stoi(s);
                if (tmp > max_value) max_value = tmp;
            } else {
                if (s.length() > max_value) max_value = s.length();
            }
        }
        return max_value;
    }
};

int main(){
    // string rawArray[] = {"alic3","bob","3","4","00000"};
    string rawArray[] = {"3glko","1"};
    vector<string> strArray(rawArray, rawArray + 2);
    
    // for (auto &x : strArray){
    //     cout << x << endl;
    //     for (auto &m : x){
    //         cout << m << ": ";
    //         cout << m - '0' << ", " << m - '9' << endl;
    //     }
    // }

    Solution S;
    int res = S.maximumValue(strArray);
    cout << res << endl;
    return 0;
}
