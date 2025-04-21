//
// Created by xiaha on 25-4-21.
/*
*2145. 统计隐藏数组数目
给你一个下标从 0 开始且长度为 n 的整数数组 differences ，它表示一个长度为 n + 1 的 隐藏 数组 相邻 元素之间的 差值 。
更正式的表述为：我们将隐藏数组记作 hidden ，那么 differences[i] = hidden[i + 1] - hidden[i] 。
同时给你两个整数 lower 和 upper ，它们表示隐藏数组中所有数字的值都在 闭 区间 [lower, upper] 之间。
比方说，differences = [1, -3, 4] ，lower = 1 ，upper = 6 ，那么隐藏数组是一个长度为 4 且所有值都在 1 和 6 （包含两者）之间的数组。
[3, 4, 1, 5] 和 [4, 5, 2, 6] 都是符合要求的隐藏数组。
[5, 6, 3, 7] 不符合要求，因为它包含大于 6 的元素。
[1, 2, 3, 4] 不符合要求，因为相邻元素的差值不符合给定数据。
请你返回 符合 要求的隐藏数组的数目。如果没有符合要求的隐藏数组，请返回 0 。
*/

#include <limits>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfArrays(vector<int> &differences, int lower, int upper) {
        // 假设第一个元素为int的最小值;
        // 可能得最小值
        long possibleMin = 0;
        // 可能得最大值
        long possibleMax = possibleMin;
        long last = possibleMin;
        for (int &diff: differences) {
            last += diff;
            possibleMin = min(possibleMin, last);
            possibleMax = max(possibleMax, last);
        }
        // 可能得最小值和最大值都在lower和upper之间 possibleMin -> lower ; possibleMax -> possibleMax + (lower - possibleMin)
        // 找到 possibleMax的成长上限 possibleMax 小于等于 upper
        possibleMax = possibleMax + (lower - possibleMin);

        /*int ans = 0;
        for (; possibleMax <= upper; possibleMax++) {
            ans++;
        }
        return ans;*/
        int ans = upper - possibleMax + 1;
        return max(ans, 0);
    }
};
