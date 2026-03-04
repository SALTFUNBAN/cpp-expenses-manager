cmake_minimum_required(VERSION 3.16)

project(ExpensesManager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
file(COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR})

add_executable(ExpensesManager
    src/ExpenseManager.cpp
    src/main.cpp
    src/Storage.cpp
)

target_include_directories(ExpensesManager PRIVATE include)