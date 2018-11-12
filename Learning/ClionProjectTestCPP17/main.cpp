#include <memory>

#include <memory>

#include <iostream>
#include <memory>
#include <vector>
#include "HeaderFiles/TestClass.h"
#include "HeaderFiles/PassValuesBetweenThreads.h"
#include "HeaderFiles/ApplyTupleFunction.h"
#include "HeaderFiles/RangeBasedAlgorithms.h"
#include "HeaderFiles/ExecteTaskAsychronously.h"
#include "HeaderFiles/Lambda.h"
#include "HeaderFiles/ChangeAlgorithms.h"
#include "HeaderFiles/CustomAllocator.h"
#include "HeaderFiles/TemplateExample.h"


std::unique_ptr<TestClass> testClass;
std::unique_ptr<PassValuesBetweenThreads> passValue;
std::unique_ptr<ApplyTupleFunction> applyTuple;
std::unique_ptr<RangeBasedAlgorithms> rangeBased;
std::unique_ptr<ExecteTaskAsychronously> executeAsync;
std::unique_ptr<Lambda> lambdaClass;
std::unique_ptr<ChangeAlgorithms> changeAlgorithms;
std::unique_ptr<CustomAllocator> customAllocator;
std::unique_ptr<TemplateExample> templateExample;

int main() {

    testClass = std::make_unique<TestClass>();
    passValue = std::make_unique<PassValuesBetweenThreads>();
    applyTuple = std::make_unique<ApplyTupleFunction>();
    rangeBased = std::make_unique<RangeBasedAlgorithms>();
    executeAsync = std::make_unique<ExecteTaskAsychronously>();
    lambdaClass = std::make_unique<Lambda>();
    changeAlgorithms = std::make_unique<ChangeAlgorithms>();
    customAllocator = std::make_unique<CustomAllocator>();
    templateExample = std::make_unique<TemplateExample>();

    testClass->SortRange();
    testClass->useOptional();
    testClass->separatedCommands();
    testClass->testCommands2();

    lambdaClass->checkLambdaFncs();

    changeAlgorithms->changeFnc();
    changeAlgorithms->nonChangeFnc();
    changeAlgorithms->Sorting();
    changeAlgorithms->NumericAlgs();

    customAllocator->allocat();

    templateExample->tempExam();
    templateExample->multiPrint();
    templateExample->testTupleAssignment();
    templateExample->testMakeTuple();

    passValue->passValue();

    applyTuple->applyTuple();

    std::vector<int> a = {0,1,2,3,4,5,6};
    rangeBased->doWork(a);

    executeAsync->execte();
    return 0;
}