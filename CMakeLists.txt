cmake_minimum_required(VERSION 3.20)
project(DataStructureAndAlgorithm C)

set(CMAKE_C_STANDARD 99)

#add_executable(DataStructureAndAlgorithm main.c)
#add_executable(DataStructureAndAlgorithm InfixToSuffix/simple/test.c InfixToSuffix/simple/StackChar.c InfixToSuffix/simple/StackChar.h InfixToSuffix/simple/StackFloat.c InfixToSuffix/simple/StackFloat.h InfixToSuffix/simple/calc.c InfixToSuffix/simple/calc.h)
add_executable(DataStructureAndAlgorithm InfixToSuffix/universal/test.c InfixToSuffix/universal/Stack.c InfixToSuffix/universal/Stack.h InfixToSuffix/universal/calc.c InfixToSuffix/universal/calc.h)
