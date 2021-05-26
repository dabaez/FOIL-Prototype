# add_executable(main main.cpp
# ${ANTLR_SampleGrammarLexer_CXX_OUTPUTS}
#               ${ANTLR_SampleGrammarParser_CXX_OUTPUTS})
            # target_link_libraries(main antlr4_static)
add_library(dtnode DTNode.cpp)
add_library(dt DecisionTree.cpp)
add_library(afbdd AFBDD.cpp)
add_library(afbddnode AFBDDNode.cpp)
add_library(perceptron perceptron.cpp)
add_library(fpow fastpow.cpp)



add_library(errorListener errorListener.cpp)
target_link_libraries(errorListener antlr4_static)

add_executable(test_generator generator.cpp)
