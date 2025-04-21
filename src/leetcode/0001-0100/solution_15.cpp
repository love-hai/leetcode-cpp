//
// Created by xiaha on 25-4-21.
//

/*
15. 三数之和
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。
 */
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &nums) {
        // 排序
        ranges::sort(nums);
        int leftIndex = 0;
        int rightIndex = 0;
        vector<vector<int> > ans;
        for (int i = 0; i < nums.size() -2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            leftIndex = i + 1;
            rightIndex = nums.size() - 1;
            while (leftIndex < rightIndex) {
                int sum = nums[i] + nums[leftIndex] + nums[rightIndex];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[leftIndex], nums[rightIndex]});
                    while (leftIndex < rightIndex && nums[leftIndex] == nums[leftIndex + 1]) {
                        leftIndex++;
                    }
                    while (leftIndex < rightIndex && nums[rightIndex] == nums[rightIndex - 1]) {
                        rightIndex--;
                    }
                    leftIndex++;
                    rightIndex--;
                } else if (sum < 0) {
                    leftIndex++;
                } else {
                    rightIndex--;
                }
            }
        }
        return ans;
    }
};
