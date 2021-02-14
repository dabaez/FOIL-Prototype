# add_executable(main main.cpp
# ${ANTLR_SampleGrammarLexer_CXX_OUTPUTS}
#               ${ANTLR_SampleGrammarParser_CXX_OUTPUTS})
            # target_link_libraries(main antlr4_static)
add_library(fnode FNode.cpp)
add_library(fbdd FBDD.cpp)
add_library(perceptron perceptron.cpp)

add_executable(fbddtest fbddtest.cpp)

target_link_libraries(fbddtest fnode fbdd)
