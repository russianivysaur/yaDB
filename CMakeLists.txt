cmake_minimum_required(VERSION 3.25.1)
project(yadb C)
set(CMAKE_C_STANDARD 23)
enable_testing()

#tests
add_executable(block_id_test tests/file/block_id_tests.c src/file/block_id.c)
add_test(NAME block_test COMMAND block_id_test)
add_executable(page_test tests/file/page_tests.c src/file/page.c)
add_test(NAME page_test COMMAND page_test)