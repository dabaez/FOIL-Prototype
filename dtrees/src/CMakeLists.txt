add_library(dtnode DTNode.cpp)
add_library(decisiontree DecisionTree.cpp)

add_executable(test test.cpp)

target_link_libraries(test dtnode decisiontree)
