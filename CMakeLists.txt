cmake_minimum_required(VERSION 3.30)
project(leetcode_cpp)

set(CMAKE_CXX_STANDARD 20)

# 递归搜索 src/leetcode 目录及其子目录中的所有 .cpp 文件
file(GLOB_RECURSE SOURCES "src/leetcode/**/*.cpp")
# 创建一个名为 leetcode_cpp_lib 的库
add_library(leetcode_cpp_lib ${SOURCES}
        src/leetcode/2101-2200/solution_2145.cpp
)


# =========================测试单元========================= start
# 测试目录
file(GLOB_RECURSE leetcode_tests "tests/leetcode/*.cpp" )
add_executable(leetcode_tests ${leetcode_tests})
# gtest测试库
set(GOOGLETEST_VERSION "1.16.0")
add_subdirectory(include/googletest)
include_directories(${PROJECT_SOURCE_DIR}/src/ include/googletest/include)
link_directories(${PROJECT_SOURCE_DIR}/lib include/googletest)
# 链接测试库
target_link_libraries(leetcode_tests  gtest_main gtest leetcode_cpp_lib)
# ==========================测试单元========================= end


