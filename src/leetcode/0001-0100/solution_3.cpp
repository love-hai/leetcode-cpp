//
// Created by xiaha on 25-4-22.
//
#include <string>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) {
            return 0;
        }
        int start = 0, end = 1, ans = 1;
        while (end < s.length()) {
            int idx = findCharAndIndex(s, start, end - 1, s[end]);
            if (-1 == idx) {
                ans = max(ans, end - start + 1);
            } else {
                start = idx + 1;
            }
            end++;
        }
        return ans;
    }

    int findCharAndIndex(string str, int start, int end, char c) {
        for (int i = start; i <= end; i++) {
            if (str[i] == c) {
                return i;
            }
        }
        return -1;
    }
};
