#ifndef __STRINGEXTENSIONTESTFIXTURE_H
#define __STRINGEXTENSIONTESTFIXTURE_H

#include <cppunit/extensions/HelperMacros.h>
#include "StringExtension.h"

class StringExtensionTestFixture : public CppUnit::TestFixture 
{
public:
	CPPUNIT_TEST_SUITE(StringExtensionTestFixture);
	CPPUNIT_TEST(TestIntIsDouble);
	CPPUNIT_TEST(TestDoubleIsDouble);
	CPPUNIT_TEST(TestMultiplePointsAreNotDouble);
	CPPUNIT_TEST(TestStringIsNotDouble);
	CPPUNIT_TEST(TestOperatorIsOperator);
	CPPUNIT_TEST(TestOtherStringsIsNotOperator);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp() {}
	void tearDown() {}

	void TestIntIsDouble() {
		CPPUNIT_ASSERT(StringExtension::isDouble("1") == true);
	}

	void TestDoubleIsDouble() {
		CPPUNIT_ASSERT(StringExtension::isDouble("3.2") == true);
	}

	void TestMultiplePointsAreNotDouble() {
		CPPUNIT_ASSERT(StringExtension::isDouble("2.4.5") == false);
	}

	void TestStringIsNotDouble() {
		CPPUNIT_ASSERT(StringExtension::isDouble("hello") == false);
	}

	void TestOperatorIsOperator() {
		CPPUNIT_ASSERT(StringExtension::isOperator("+") == true);
		CPPUNIT_ASSERT(StringExtension::isOperator("-") == true);
		CPPUNIT_ASSERT(StringExtension::isOperator("/") == true);
		CPPUNIT_ASSERT(StringExtension::isOperator("*") == true);
	}

	void TestOtherStringsIsNotOperator() {
		CPPUNIT_ASSERT(StringExtension::isOperator("$") == false);
		CPPUNIT_ASSERT(StringExtension::isOperator("2") == false);
		CPPUNIT_ASSERT(StringExtension::isOperator("hello") == false);
	}
};

#endif