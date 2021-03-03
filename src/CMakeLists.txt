# add_executable(main main.cpp
# ${ANTLR_SampleGrammarLexer_CXX_OUTPUTS}
#               ${ANTLR_SampleGrammarParser_CXX_OUTPUTS})
            # target_link_libraries(main antlr4_static)
add_library(fnode FNode.cpp)
add_library(fbdd FBDD.cpp)
add_library(perceptron perceptron.cpp)
add_library(fbddsub FBDDsub.cpp)
add_library(fpow fastpow.cpp)

add_executable(fbddtest fbddtest.cpp)

target_link_libraries(fbddtest fnode fbdd)

add_executable(subtest subtest.cpp)

target_link_libraries(subtest fbdd fnode fbddsub)

add_library(errorListener errorListener.cpp)
target_link_libraries(errorListener antlr4_static)
