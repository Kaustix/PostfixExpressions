#ifndef __TOKENIZERTESTFIXTURE_H
#define __TOKENIZERTESTFIXTURE_H

#include <cppunit/extensions/HelperMacros.h>
#include "Tokenizer.h"

class TokenizerTestFixture : public CppUnit::TestFixture 
{
public:
	CPPUNIT_TEST_SUITE(TokenizerTestFixture);
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
};

#endif