#ifndef NICOLAS_EXAMPLES_H
#define NICOLAS_EXAMPLES_H
#include <xstring>

class NicolasExamples
{
public:
	NicolasExamples();
	virtual ~NicolasExamples() = default;
	void startTests();
	void printDirSize(const std::string& dir) const;
	void testStringView() const;
	static void testOptional();
	static void testVariant();
	static void testAny();
	static void parallelTest();
	static void cppPrintf();
	static void testNewIn17();

};
#endif
