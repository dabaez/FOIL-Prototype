# add_executable(main main.cpp
# ${ANTLR_SampleGrammarLexer_CXX_OUTPUTS}
#               ${ANTLR_SampleGrammarParser_CXX_OUTPUTS})
            # target_link_libraries(main antlr4_static)
add_library(dtnode DTNode.cpp)
add_library(dt DecisionTree.cpp)
add_library(perceptron perceptron.cpp)

