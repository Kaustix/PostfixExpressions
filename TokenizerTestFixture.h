#ifndef __TOKENIZERTESTFIXTURE_H
#define __TOKENIZERTESTFIXTURE_H

#include <cppunit/extensions/HelperMacros.h>
#include "Tokenizer.h"

class TokenizerTestFixture : public CppUnit::TestFixture 
{
public:
	CPPUNIT_TEST_SUITE(TokenizerTestFixture);
	//Parsing
	CPPUNIT_TEST(ShouldParseString);
	CPPUNIT_TEST(ShouldInitializeParserToInitialToken);
	//crtTokenType
	CPPUNIT_TEST(ShouldReturnLiteralToken);
	CPPUNIT_TEST(ShouldReturnOperatorToken);
	CPPUNIT_TEST(ShouldReturnUnknownToken);
	//CPPUNIT_TEST(ShouldReturnTheEndToken);
	CPPUNIT_TEST_SUITE_END();

private:
	Tokenizer* t;
	const std::string intLiteral = "1";
	const std::string doubleLiteral = "12.3";
	const std::string multipleLiterals = "42 18.7";
	const std::string singleOperator = "+";
	const std::string multipleOperators = "+ - * /";
	const std::string unknownChar = "^";
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

	void ShouldReturnLiteralToken() {
		t->parse(intLiteral);
		CPPUNIT_ASSERT(t->crtTokenType() == Tokenizer::Tokens::LITERAL);
	}

	void ShouldReturnOperatorToken() {
		t->parse(singleOperator);
		CPPUNIT_ASSERT(t->crtTokenType() == Tokenizer::Tokens::OPERATOR);
	}

	void ShouldReturnUnknownToken() {
		t->parse(unknownChar);
		CPPUNIT_ASSERT(t->crtTokenType() == Tokenizer::Tokens::UNKNOWN);
	}

	void ShouldReturnTheEndToken() {
		//TODO::Change to use nextToken() Instead later
	 	t->parse(intLiteral);
	 	t->crtIndex++;
	 	CPPUNIT_ASSERT(t->crtTokenType() == Tokenizer::Tokens::THEEND);
	}
};

#endif