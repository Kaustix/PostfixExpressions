#ifndef __POSTFIXEXPRTESTFIXTURE_H
#define __POSTFIXEXPRTESTFIXTURE_H

#include <cppunit/extensions/HelperMacros.h>
#include "PostfixExpr.h"
#include "Tokenizer.h"
#include "exceptions.h"

class PostfixExprTestFixture : public CppUnit::TestFixture 
{
public:
	CPPUNIT_TEST_SUITE(PostfixExprTestFixture);
	CPPUNIT_TEST(ShouldCorrectlyEvaluatePostFixExpression1);
	CPPUNIT_TEST(ShouldCorrectlyEvaluatePostFixExpression2);
	CPPUNIT_TEST(ShouldCorrectlyEvaluatePostFixExpressionNegativeNumbers);
	CPPUNIT_TEST(ShouldEvaluateOperatorPlus);
	CPPUNIT_TEST(ShouldEvaluateOperatorMinus);
	CPPUNIT_TEST(ShouldEvaluateOperatorStar);
	CPPUNIT_TEST(ShouldEvaluateOperatorSlash);
	CPPUNIT_TEST_EXCEPTION(ShouldThrowSyntaxErrorIfEmpty, SyntaxError);
	CPPUNIT_TEST_EXCEPTION(ShouldThrowSyntaxErrorIfSingleLiteralAtFront, SyntaxError);
	CPPUNIT_TEST_EXCEPTION(ShouldThrowSyntaxErrorIfNoOperatorPresent, SyntaxError);
	CPPUNIT_TEST_EXCEPTION(ShouldThrowSyntaxErrorIfNoLiteralPresent, SyntaxError);
	CPPUNIT_TEST_EXCEPTION(ShouldThrowSyntaxErrorIfExtraOperatorPresent, SyntaxError);
	CPPUNIT_TEST_EXCEPTION(ShouldThrowSyntaxErrorIfExtraLiteralPresent, SyntaxError);
	CPPUNIT_TEST_SUITE_END();
private:
	PostfixExpr* p;
	const std::string expr1 = "10 2 4 +*";
	const std::string expr2 = "10 2 - 7 + 3 /";
	const std::string expr3 = "0 1 -";

public:
	void setUp(){
		p = new PostfixExpr();
	}

	void tearDown(){
		delete p;
	}

	void ShouldCorrectlyEvaluatePostFixExpression1() {
		CPPUNIT_ASSERT(p->evaluate(expr1) == 60);
	}

	void ShouldCorrectlyEvaluatePostFixExpression2() {
		CPPUNIT_ASSERT(p->evaluate(expr2) == 5);
	}

	void ShouldCorrectlyEvaluatePostFixExpressionNegativeNumbers() {
		CPPUNIT_ASSERT(p->evaluate(expr3) == -1);
	}

	void ShouldEvaluateOperatorPlus() {
		CPPUNIT_ASSERT(p->evaluateOperator(Tokenizer::OperatorValue::PLUS, 2.0, 1.0) == 3.0);
	}

	void ShouldEvaluateOperatorMinus() {
		CPPUNIT_ASSERT(p->evaluateOperator(Tokenizer::OperatorValue::MINUS, 5.0, 3.0) == 2.0);
	}

	void ShouldEvaluateOperatorStar() {
		CPPUNIT_ASSERT(p->evaluateOperator(Tokenizer::OperatorValue::STAR, 2.0, 2.0) == 4.0);
	}

	void ShouldEvaluateOperatorSlash() {
		CPPUNIT_ASSERT(p->evaluateOperator(Tokenizer::OperatorValue::SLASH, 50.0, 5.0) == 10.0);
	}

	void ShouldThrowSyntaxErrorIfEmpty() {
		p->evaluate("");
	}

	void ShouldThrowSyntaxErrorIfSingleLiteralAtFront() {
		p->evaluate("10 +");
	}

	void ShouldThrowSyntaxErrorIfNoLiteralPresent() {
		p->evaluate("+- /");
	}	

	void ShouldThrowSyntaxErrorIfNoOperatorPresent() {
		p->evaluate("10 2 6");
	}

	void ShouldThrowSyntaxErrorIfExtraLiteralPresent() {
		p->evaluate("34 8 1 +");
	}

	void ShouldThrowSyntaxErrorIfExtraOperatorPresent() {
		p->evaluate("3 22 +-/");
	}

};

#endif