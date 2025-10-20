cmake_minimum_required(VERSION 3.16)
PROJECT (HELLO)
SET(CMAKE_CXX_FLAGS "-Wno-deprecated-declarations")
ENABLE_TESTING()

# 让 find_package 能找到我们本地安装的第三方包（如 GTest）
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/third_party/gtest")
ADD_SUBDIRECTORY(src bin)
ADD_SUBDIRECTORY(lib lib)
ADD_SUBDIRECTORY(tests)