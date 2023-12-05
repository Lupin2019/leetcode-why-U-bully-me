#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        bool flag = false;
        string buffer, res;
        unordered_map<string, string> dict;
        for (auto &p : knowledge){
            dict[p[0]] = p[1];
        }
        for (char c : s){
            if (c == '('){flag = true;}
            else if(c == ')'){
                if(dict.count(buffer) > 0){
                    res += dict[buffer];
                } else{
                    res.push_back('?');
                }
                buffer.clear();
                flag = false;
            } else {
                if(flag){
                    buffer.push_back(c);
                } else{
                    res.push_back(c);
                }
            }
        }
        return res;
    }
};

int main(){
    string s = "(name)is(age)yearsold";
    return 0;
}