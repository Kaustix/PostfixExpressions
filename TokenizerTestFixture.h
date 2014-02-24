#ifndef __TOKENIZERTESTFIXTURE_H
#define __TOKENIZERTESTFIXTURE_H

#include <cppunit/extensions/HelperMacros.h>
#include "Tokenizer.h"

class TokenizerTestFixture : public CppUnit::TestFixture 
{
public:
	CPPUNIT_TEST_SUITE(TokenizerTestFixture);
	CPPUNIT_TEST(ShouldParseString);
	CPPUNIT_TEST(ShouldInitializeParserToInitialToken);
	CPPUNIT_TEST_SUITE_END();

private:
	Tokenizer* t;
	const std::string intLiteral = "1";
	const std::string doubleLiteral = "12.3";
	const std::string multipleLiterals = "42 18.7";
	const std::string operators = "+ - * /";
	const std::string spaces = "  10   +   2  ";

public:
	void setUp(){
		t = new Tokenizer;
	}

	void tearDown(){
		delete t;
	}

	void ShouldParseString() {
		t->parse(intLiteral);
		CPPUNIT_ASSERT(t->strList[0] == "1");
	}

	void ShouldInitializeParserToInitialToken() {
		t->parse(intLiteral);
		CPPUNIT_ASSERT(t->crtIndex == 0);
	}
};

#endif