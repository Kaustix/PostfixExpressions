#ifndef __POSTFIXEXPRTESTFIXTURE_H
#define __POSTFIXEXPRTESTFIXTURE_H

#include <cppunit/extensions/HelperMacros.h>
#include "PostfixExpr.h"
#include "exceptions.h"

class PostfixExprTestFixture : public CppUnit::TestFixture 
{
public:
	CPPUNIT_TEST_SUITE(PostfixExprTestFixture);
	CPPUNIT_TEST_SUITE_END();

	void setUp(){
	}

	void tearDown(){
	}
};

#endif