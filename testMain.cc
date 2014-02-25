#include <cppunit/ui/text/TestRunner.h>
#include "TokenizerTestFixture.h"
#include "StringExtensionTestFixture.h"
#include "PostfixExprTestFixture.h"

int main(void)
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(TokenizerTestFixture::suite());
	runner.addTest(StringExtensionTestFixture::suite());
	runner.addTest(PostfixExprTestFixture::suite());
	runner.run();

	return 0;
}