add_library(hpcpp ex1.cpp)
target_include_directories(hpcpp PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(hpcpp PRIVATE ${CMAKE_SOURCE_DIR}/ext/eigen)
target_link_libraries(hpcpp PUBLIC OpenMP::OpenMP_CXX)
