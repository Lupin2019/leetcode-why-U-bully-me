#include <bits/stdc++.h>
// #include <fmt>
using namespace std;


class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        unordered_map<char, int> chars_counter;
        for (char c: chars) ++chars_counter[c];

        int res = 0;
        for (string word : words) {
            unordered_map<char, int> words_counter;
            for (char c: word) ++words_counter[c];
            bool OK = true;
            for (auto &[k,v] : words_counter) {
                if (v > chars_counter[k]) {
                    OK = false;
                    break;
                }
            }   
            if (OK) res += word.size();
        }

        return res;
    }
};
