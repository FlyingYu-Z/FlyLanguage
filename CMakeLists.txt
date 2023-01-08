cmake_minimum_required(VERSION 3.22)
#CMAKE_MINIMUM_REQUIRED(VERSION 3.7 FATAL_ERROR)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

#set(ENV{http_proxy} "http://127.0.0.1:10809")
#set(ENV{https_proxy} "https://127.0.0.1:10809")
#set(ENV{http_proxy} "socks5://127.0.0.1:10809")
#set(ENV{https_proxy} "socks5://127.0.0.1:10809")

enable_testing()
project(FlyLanguage)
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(fmt
        URL https://github.com/fmtlib/fmt/archive/refs/tags/9.1.0.tar.gz)
FetchContent_MakeAvailable(fmt)

# required if linking to static library
add_definitions(-DANTLR4CPP_STATIC)

# using /MD flag for antlr4_runtime (for Visual C++ compilers only)
set(ANTLR4_WITH_STATIC_CRT OFF)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -save-temps -fpermissive")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -save-temps -fpermissive")

# Specify the version of the antlr4 library needed for this project.
# By default the latest version of antlr4 will be used.  You can specify a
# specific, stable version by setting a repository tag value or a link
# to a zip file containing the libary source.
set(ANTLR4_TAG 4.11.1)
set(ANTLR4_ZIP_REPOSITORY https://github.com/antlr/antlr4/archive/refs/tags/4.11.1.zip)

# add external build for antlrcpp
include(ExternalAntlr4Cpp)
# add antrl4cpp artifacts to project environment
include_directories(${ANTLR4_INCLUDE_DIRS})

set(ANTLR_EXECUTABLE /usr/local/lib/antlr-4.11.1-complete.jar)
find_package(ANTLR REQUIRED)
#find_package(antlr4-runtime REQUIRED)
#find_package(antlr4-generator REQUIRED)

# Call macro to add lexer and grammar to your build dependencies.
antlr_target(FlyScriptLexer FlyScriptLexer.g4 LEXER
        PACKAGE beingyi)
antlr_target(FlyScriptParser FlyScriptParser.g4 PARSER
        PACKAGE beingyi
        DEPENDS_ANTLR FlyScriptLexer
        COMPILE_FLAGS -lib ${ANTLR_FlyScriptLexer_OUTPUT_DIR})

# include generated files in project environment
include_directories(${ANTLR_FlyScriptLexer_OUTPUT_DIR})
include_directories(${ANTLR_FlyScriptParser_OUTPUT_DIR})


include_directories(
        ${PROJECT_SOURCE_DIR}/generated
        ${PROJECT_SOURCE_DIR}/utils
        ${PROJECT_SOURCE_DIR}/src/convertor
        ${PROJECT_SOURCE_DIR}/src/value
        ${PROJECT_SOURCE_DIR}/src/ir
        ${PROJECT_SOURCE_DIR}/src/utils
        ${PROJECT_SOURCE_DIR}/src/runtime
        ${PROJECT_SOURCE_DIR}/src/runtime/value
        ${PROJECT_SOURCE_DIR}/src/runtime/value/compare
)

file(GLOB SOURCE_FILES
        "${PROJECT_SOURCE_DIR}/generated/*.cpp"
        "${PROJECT_SOURCE_DIR}/utils/*.cpp"
        "${PROJECT_SOURCE_DIR}/utils/*.h"
        "${PROJECT_SOURCE_DIR}/src/convertor/*.h"
        "${PROJECT_SOURCE_DIR}/src/convertor/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/convertor/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/value/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/value/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/ir/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/ir/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/ir/*.h"
        "${PROJECT_SOURCE_DIR}/src/utils/*.h"
        "${PROJECT_SOURCE_DIR}/src/runtime/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/runtime/*.h"
        "${PROJECT_SOURCE_DIR}/src/runtime/value/*.h"
        "${PROJECT_SOURCE_DIR}/src/runtime/value/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/runtime/value/compare/*.h"
        "${PROJECT_SOURCE_DIR}/src/runtime/value/compare/*.cpp"
        )

find_package(Threads)


add_executable(FlyLanguage main.cpp
        ${ANTLR_SampleGrammarLexer_CXX_OUTPUTS}
        ${ANTLR_SampleGrammarParser_CXX_OUTPUTS}
        ${SOURCE_FILES}

)
target_link_libraries(FlyLanguage antlr4_static ${CMAKE_THREAD_LIBS_INIT} fmt)
