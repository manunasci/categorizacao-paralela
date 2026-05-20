cmake_minimum_required(VERSION 3.27)
project(CategorizacaoParalela)

set(CMAKE_CXX_STANDARD 17)

add_executable(CategorizacaoParalela main.cpp
        DataValidator.cpp
        DataValidator.h
        FileData.hpp
        DataAnalyzer.cpp
        DataAnalyzer.hpp)
