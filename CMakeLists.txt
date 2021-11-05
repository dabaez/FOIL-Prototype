# minimum required CMAKE version
CMAKE_MINIMUM_REQUIRED(VERSION 3.7 FATAL_ERROR)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

project(invint LANGUAGES CXX VERSION 0.0.1)

# compiler must be 11 or 14
set(CMAKE_CXX_STANDARD 14)

# required if linking to static library
add_definitions(-DANTLR4CPP_STATIC)

# using /MD flag for antlr4_runtime (for Visual C++ compilers only)
set(ANTLR4_WITH_STATIC_CRT OFF)
# add external build for antlrcpp
include(ExternalAntlr4Cpp)
# add antrl4cpp artifacts to project environment
include_directories(${ANTLR4_INCLUDE_DIRS})

# set variable pointing to the antlr tool that supports C++
# this is not required if the jar file can be found under PATH environment
set(ANTLR_EXECUTABLE ${CMAKE_CURRENT_SOURCE_DIR}/include/antlr-4.9.1-complete.jar)
# add macros to generate ANTLR Cpp code from grammar
find_package(ANTLR REQUIRED)

# Call macro to add lexer and grammar to your build dependencies.
antlr_target(SampleGrammarLexer invLexer.g4 LEXER
             PACKAGE antlrcpptest)
antlr_target(SampleGrammarParser invParser.g4 PARSER
             PACKAGE antlrcpptest
             DEPENDS_ANTLR SampleGrammarLexer
             COMPILE_FLAGS -lib ${ANTLR_SampleGrammarLexer_OUTPUT_DIR} )

# include generated files in project environment
include_directories(${ANTLR_SampleGrammarLexer_OUTPUT_DIR})
include_directories(${ANTLR_SampleGrammarParser_OUTPUT_DIR})

include_directories(include)
add_subdirectory(src)

add_library(gVisitor src/greedyVisitor.cpp
   ${ANTLR_SampleGrammarLexer_CXX_OUTPUTS}
   ${ANTLR_SampleGrammarParser_CXX_OUTPUTS})
target_link_libraries(gVisitor antlr4_static fpow)

add_library(qChecker src/queryChecker.cpp
   ${ANTLR_SampleGrammarLexer_CXX_OUTPUTS}
   ${ANTLR_SampleGrammarParser_CXX_OUTPUTS})
target_link_libraries(qChecker antlr4_static)

add_library(qChecker2 src/queryChecker2.cpp
   ${ANTLR_SampleGrammarLexer_CXX_OUTPUTS}
   ${ANTLR_SampleGrammarParser_CXX_OUTPUTS})
target_link_libraries(qChecker2 antlr4_static)

add_library(paperalgo src/paperalgo.cpp
   ${ANTLR_SampleGrammarLexer_CXX_OUTPUTS}
   ${ANTLR_SampleGrammarParser_CXX_OUTPUTS})
target_link_libraries(paperalgo antlr4_static)

add_library(qChecker3 src/queryChecker3.cpp
   ${ANTLR_SampleGrammarLexer_CXX_OUTPUTS}
   ${ANTLR_SampleGrammarParser_CXX_OUTPUTS})
target_link_libraries(qChecker3 antlr4_static)

add_library(paperalgofull src/paperalgofull.cpp
   ${ANTLR_SampleGrammarLexer_CXX_OUTPUTS}
   ${ANTLR_SampleGrammarParser_CXX_OUTPUTS})
target_link_libraries(paperalgofull antlr4_static)

file(GLOB SOURCES "*.cpp")

add_executable(main src/main.cpp
   ${ANTLR_SampleGrammarLexer_CXX_OUTPUTS}
   ${ANTLR_SampleGrammarParser_CXX_OUTPUTS})

target_link_libraries(main antlr4_static perceptron dt dtnode afbdd afbddnode gVisitor qChecker paperalgo qChecker2 paperalgofull qChecker3 errorListener)
