# step8: tests 子工程

# 使用系统预编译的 GoogleTest
find_package(GTest REQUIRED CONFIG)

# 生成测试可执行文件（仅包含测试；使用预编译 GTest，保留 GTest 自带入口或通过 GTest::GTest 直接链接断言实现）
ADD_EXECUTABLE(helloTest
	main.cpp
	test.cpp
)

# 对 MinGW/Windows 避免使用 quick_exit（某些环境缺少相应导入符号）
target_compile_definitions(helloTest PRIVATE GTEST_HAS_QUICK_EXIT=0)

## 需要头文件可见时也可加上（通常不需要，因为 hello 已设置 PUBLIC include）：
# target_include_directories(helloTest PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include)

# 链接被测库 hello 与 GTest（注意：已提供自定义 main.cpp，不使用 gtest_main）
if (TARGET GTest::GTest)
	target_link_libraries(helloTest PRIVATE hello GTest::GTest)
elseif (TARGET GTest::gtest)
	target_link_libraries(helloTest PRIVATE hello GTest::gtest)
else()
	message(FATAL_ERROR "No suitable GTest imported target found (GTest::GTest or GTest::gtest).")
endif()

# MinGW 下显式链接 UCRT 基础库，解决 __imp__Exit / __imp_quick_exit 未解析
if (MINGW)
	# 在非 UCRT 的 MinGW 环境下，mingwex 提供 quick_exit/_Exit 的兼容实现
	target_link_libraries(helloTest PRIVATE mingwex)
endif()

# 注册测试
ADD_TEST(NAME helloTest COMMAND helloTest)