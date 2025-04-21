//
// Created by xiaha on 25-4-21.
//
/*
*209. 长度最小的子数组
给定一个含有 n 个正整数的数组和一个正整数 target 。
找出该数组中满足其总和大于等于 target 的长度最小的 子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，
并返回其长度。如果不存在符合条件的子数组，返回 0 。
*/

#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int left = 0, right = 0;
        int sum = 0;
        int ans = INT_MAX;
        while (right < nums.size()) {
            sum += nums[right++];
            while (sum >= target) {
                ans = min(ans, right - left);
                sum -= nums[left];
                left++;
            }
        }
        if (ans == INT_MAX) {
            ans = 0;
        }
        return ans;
    }
};
