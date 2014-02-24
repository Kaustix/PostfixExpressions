#include <cppunit/ui/text/TestRunner.h>
#include "TokenizerTestFixture.h"

int main(void)
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(TokenizerTestFixture::suite());
	runner.run();

	return 0;
}