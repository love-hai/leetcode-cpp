//
// Created by xiaha on 25-4-20.
// 森林中有未知数量的兔子。提问其中若干只兔子 "还有多少只兔子与你（指被提问的兔子）颜色相同?" ，
// 将答案收集到一个整数数组 answers 中，其中 answers[i] 是第 i 只兔子的回答。
// 给你数组 answers ，返回森林中兔子的最少数量。

#include <vector>
#include <map>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int numRabbits(vector<int> &answers) {
        map<int, int> m;
        for (int &answer: answers) {
            m[answer + 1]++;
        }
        int ans = 0;
        for (auto &[k, v]: m) {
            // k 是相同颜色兔子的数量，v 是回答这个问题的兔子数量
            ans = ans + ((v - 1) / k + 1) * k;
        }
        return ans;
    }
};
