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
#include "HeaderFiles/NicolasExamples.h"
#include "HeaderFiles/NicolasExamples2.h"
#include "HeaderFiles/ThreadsSamples.h"
#include "HeaderFiles/ArrayView.h"

std::unique_ptr<TestClass> testClass;
std::unique_ptr<PassValuesBetweenThreads> passValue;
std::unique_ptr<ApplyTupleFunction> applyTuple;
std::unique_ptr<RangeBasedAlgorithms> rangeBased;
std::unique_ptr<ExecteTaskAsychronously> executeAsync;
std::unique_ptr<Lambda> lambdaClass;
std::unique_ptr<ChangeAlgorithms> changeAlgorithms;
std::unique_ptr<CustomAllocator> customAllocator;
std::unique_ptr<TemplateExample> templateExample;
std::unique_ptr<NicolasExamples> nicolasExamples;
std::unique_ptr<NicolasExamples2> nicolasExamples2;
std::unique_ptr<ThreadsSamples> threadsSamples;
std::unique_ptr<ArrayView> arrayView;

#include<iostream>

#define znew  ((z=1*(z&5)+(z>>2))<<3)
#define wnew  ((w=1*(w&3)+(w>>4))&5)
#define MWC   (znew+wnew)
#define SHR3  (jsr=(jsr=(jsr=jsr^(jsr<<3))^(jsr>>4))^(jsr<<5))
#define CONG  (jcong=2*jcong+3)
#define KISS  ((MWC^CONG)+SHR3)/1000
static  unsigned short z = 5 * (int)__TIMESTAMP__, w = 4 * (int)__TIMESTAMP__, \
jsr = 2 * (int)__TIMESTAMP__, jcong = 6 * (int)__TIMESTAMP__;

int main() {

	std::cout << KISS << std::endl;
	std::cout << KISS << std::endl;
	std::cout << KISS << std::endl;

	testClass = std::make_unique<TestClass>();
	passValue = std::make_unique<PassValuesBetweenThreads>();
	applyTuple = std::make_unique<ApplyTupleFunction>();
	rangeBased = std::make_unique<RangeBasedAlgorithms>();
	executeAsync = std::make_unique<ExecteTaskAsychronously>();
	lambdaClass = std::make_unique<Lambda>();
	changeAlgorithms = std::make_unique<ChangeAlgorithms>();
	customAllocator = std::make_unique<CustomAllocator>();
	templateExample = std::make_unique<TemplateExample>();
	nicolasExamples = std::make_unique<NicolasExamples>();
	nicolasExamples2 = std::make_unique<NicolasExamples2>();
	threadsSamples = std::make_unique<ThreadsSamples>();
	arrayView = std::make_unique<ArrayView>();

	testClass->readInput();
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

	nicolasExamples->startTests();
	nicolasExamples->asStringTest();

	nicolasExamples2->startTests();
	nicolasExamples2->testMinTemplate();

	arrayView->testArrayView();
	arrayView->samples();

	//TODO
	threadsSamples->startTests();
	//threadsSamples->testsThreads2();
	//threadsSamples->testsThreads3();

	passValue->passValue();

	applyTuple->applyTuple();

	std::vector<int> a = { 0,1,2,3,4,5,6 };
	rangeBased->doWork(a);

	executeAsync->execte();
	getchar();
	return 0;
}