#ifndef __TOKENIZERTESTFIXTURE_H
#define __TOKENIZERTESTFIXTURE_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Tokenizer.h"

class TokenizerTestFixture : public CppUnit::TestFixture 
{
public:
	CPPUNIT_TEST_SUITE(TokenizerTestFixture);
	//Parsing
	CPPUNIT_TEST(ShouldParseString);
	CPPUNIT_TEST(ShouldInitializeParserToInitialToken);
	CPPUNIT_TEST(ShouldParseMultipleLiterals);
	CPPUNIT_TEST(ShouldParseMultipleOperators);
	CPPUNIT_TEST(ShouldParsePostfixExpression);
	//crtTokenType
	CPPUNIT_TEST(ShouldReturnLiteralToken);
	CPPUNIT_TEST(ShouldReturnOperatorToken);
	CPPUNIT_TEST(ShouldReturnUnknownToken);
	CPPUNIT_TEST(ShouldReturnTheEndToken);
	//crtTokenValue
	CPPUNIT_TEST(ShouldReturnLiteralValue);
	CPPUNIT_TEST(ShouldReturnOperatorValue);
	//nextToken
	CPPUNIT_TEST(ShouldIncrementNextToken);

	CPPUNIT_TEST_SUITE_END();

private:
	Tokenizer* t;
	const std::string intLiteral = "1";
	const std::string doubleLiteral = "12.3";
	const std::string multipleLiterals = "42 18.7";
	const std::string singleOperator = "+";
	const std::string multipleOperators = "+-*/";
	const std::string unknownChar = "^";
	const std::string postfixExpression = "2 4.5 1 +-";
public:
	void setUp(){
		t = new Tokenizer;
	}

	void tearDown(){
		delete t;
	}

	//Parsing
	void ShouldParseString() {
		t->parse(intLiteral);
		CPPUNIT_ASSERT(t->strList[0] == "1");
	}

	void ShouldInitializeParserToInitialToken() {
		t->parse(intLiteral);
		CPPUNIT_ASSERT(t->crtIndex == 0);
	}

	void ShouldParseMultipleLiterals() {
		t->parse(multipleLiterals);
		CPPUNIT_ASSERT(t->strList[0] == "42");
		CPPUNIT_ASSERT(t->strList[1] == "18.7");
	}

	void ShouldParseMultipleOperators() {
		t->parse(multipleOperators);
		CPPUNIT_ASSERT(t->strList[0] == "+");
		CPPUNIT_ASSERT(t->strList[1] == "-");
		CPPUNIT_ASSERT(t->strList[2] == "*");
		CPPUNIT_ASSERT(t->strList[3] == "/");
	}

	void ShouldParsePostfixExpression() {
		t->parse(postfixExpression);
		CPPUNIT_ASSERT(t->strList[0] == "2");
		CPPUNIT_ASSERT(t->strList[1] == "4.5");
		CPPUNIT_ASSERT(t->strList[2] == "1");
		CPPUNIT_ASSERT(t->strList[3] == "+");
		CPPUNIT_ASSERT(t->strList[4] == "-");
	}

	//crtTokenType
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
	 	t->parse(intLiteral);
	 	t->crtIndex++;
	 	CPPUNIT_ASSERT(t->crtTokenType() == Tokenizer::Tokens::THEEND);
	}

	//crtTokenValue
	void ShouldReturnLiteralValue() {
		t->parse(intLiteral);
		CPPUNIT_ASSERT(t->crtTokenValue().literalVal == 1.0);
	}

	void ShouldReturnOperatorValue() {
		t->parse(singleOperator);
		CPPUNIT_ASSERT(t->crtTokenValue().opVal == Tokenizer::OperatorValue::PLUS);
	}

	//nextToken
	void ShouldIncrementNextToken() {
		t->parse(intLiteral);
		t->nextToken();
		CPPUNIT_ASSERT(t->crtIndex == 1);
	}
};

#endif