//
// Created by xiaha on 25-4-21.
//
#include <iostream>
#include <vector>
#include "leetcode/0001-0100/solution_15.cpp"
#include "gtest/gtest.h"

TEST(Solution,threeSum) {
    Solution solution;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int> > ans = solution.threeSum(nums);
    for (auto & an : ans) {
        cout << an[0] << " " << an[1] << " " << an[2] << endl;
    }
}