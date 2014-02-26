#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "PostfixExpr.h"
#include "exceptions.h"

int main(void) {
	PostfixExpr* postfixExprEvaluator = new PostfixExpr();

	std::ifstream file("PostfixExprFile.txt");
	std::string postfixExpr;

	std::cout << std::endl << "******STARTING Post-fix Expression Evaluator*******" << std::endl << std::endl;

	while(std::getline(file, postfixExpr)) {
		if (postfixExpr.empty()) continue;
		std::cout << postfixExpr << std::endl;
		try {
			std::cout << (postfixExprEvaluator->evaluate(postfixExpr)) << std::endl << std::endl;
		}
		catch (const std::runtime_error& e)
		{
			std::cout << e.what() << std::endl << std::endl;
		}
	}

	file.close();
	std::cout << "******STOPPING Post-fix Expression Evaluator*******" << std::endl;

	return 0;
}