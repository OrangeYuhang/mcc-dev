cmake_minimum_required(VERSION 3.16)

project(mcc C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 编译器核心库：src/ 下所有 .c 文件
file(GLOB MCC_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")
add_library(mcc STATIC ${MCC_SOURCES})
target_include_directories(mcc PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

# 测试：test/ 下每个子目录对应一个测试程序（含其数据文件），用 ctest 运行
include(CTest)
if(BUILD_TESTING)
    file(GLOB TEST_DIRS LIST_DIRECTORIES true CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/test/*")
    foreach(test_dir ${TEST_DIRS})
        if(NOT IS_DIRECTORY ${test_dir})
            continue()
        endif()
        file(GLOB test_sources CONFIGURE_DEPENDS "${test_dir}/*.c")
        if(NOT test_sources)
            continue()  # 目录存在但没有 .c，尚未编写的测试
        endif()
        get_filename_component(test_name ${test_dir} NAME)
        add_executable(${test_name} ${test_sources})
        target_link_libraries(${test_name} PRIVATE mcc)
        # 测试程序相对自身目录读取数据文件（如 test_file.txt）
        add_test(NAME ${test_name} COMMAND ${test_name} WORKING_DIRECTORY ${test_dir})
    endforeach()
endif()
