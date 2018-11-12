cmake_minimum_required(VERSION 3.12)
project(test17)

set(CMAKE_CXX_STANDARD 17)

add_executable(test17 main.cpp SourceFiles/TestClass.cpp HeaderFiles/TestClass.h SourceFiles/ApplyTupleFunction.cpp HeaderFiles/ApplyTupleFunction.h SourceFiles/PassValuesBetweenThreads.cpp HeaderFiles/PassValuesBetweenThreads.h HeaderFiles/Includes.h SourceFiles/RangeBasedAlgorithms.cpp HeaderFiles/RangeBasedAlgorithms.h SourceFiles/Observer.cpp HeaderFiles/Observer.h HeaderFiles/ClassTemplateSFINAE.h SourceFiles/ExecteTaskAsychronously.cpp HeaderFiles/ExecteTaskAsychronously.h SourceFiles/Lambda.cpp HeaderFiles/Lambda.h SourceFiles/ChangeAlgorithms.cpp HeaderFiles/ChangeAlgorithms.h SourceFiles/CustomAllocator.cpp HeaderFiles/CustomAllocator.h SourceFiles/TemplateExample.cpp HeaderFiles/TemplateExample.h)