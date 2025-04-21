//
// Created by xiaha on 25-4-21.
//

#include <vector>
#include "leetcode/0201-0300/solution_209.cpp"
#include "gtest/gtest.h"

TEST(Solution, minSubArrayLen) {
    Solution solution;
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    EXPECT_EQ(solution.minSubArrayLen(target, nums), 2);
}


