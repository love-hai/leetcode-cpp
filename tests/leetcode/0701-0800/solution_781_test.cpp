#include <iostream>
#include <vector>
#include "leetcode/2101-2200/solution_2145.cpp"
#include "gtest/gtest.h"


TEST(Solution, numberOfArrays) {
    Solution solution;
    vector<int> differences = {1, -3, 4};
    int lower = 1;
    int upper = 6;
    EXPECT_EQ(solution.numberOfArrays(differences, lower, upper), 2);
    // 输入：differences = [3,-4,5,1,-2], lower = -4, upper = 5
    // 输出：4
    differences = {3, -4, 5, 1, -2};// -4 2
    lower = -4;
    upper = 5;
    EXPECT_EQ(solution.numberOfArrays(differences, lower, upper), 4);
    // 输入：differences = [4,-7,2], lower = 3, upper = 6
    // 输出：0

    differences = {4, -7, 2};
    lower = 3;
    upper = 6;
    EXPECT_EQ(solution.numberOfArrays(differences, lower, upper), 0);
}
