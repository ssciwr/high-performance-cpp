add_executable(tests tests.cpp test_ex1.cpp test_ex2.cpp)
target_link_libraries(tests PUBLIC hpcpp Catch2::Catch2)

# allow user to run tests with `make test` or `ctest`
catch_discover_tests(tests)
