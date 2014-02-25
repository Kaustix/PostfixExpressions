#ifndef __POSTFIXEXPRTESTFIXTURE_H
#define __POSTFIXEXPRTESTFIXTURE_H

#include <cppunit/extensions/HelperMacros.h>
#include "PostfixExpr.h"
#include "exceptions.h"

class PostfixExprTestFixture : public CppUnit::TestFixture 
{
public:
	CPPUNIT_TEST_SUITE(PostfixExprTestFixture);
	CPPUNIT_TEST(ShouldCorrectlyEvaluatePostFixExpression1);
	CPPUNIT_TEST(ShouldCorrectlyEvaluatePostFixExpression2);
	CPPUNIT_TEST_SUITE_END();
private:
	PostfixExpr* p;
	const std::string expr1 = "10 2 4 +*";
	const std::string expr2 = "10 2 - 7 + 3 /";

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
};

#endif