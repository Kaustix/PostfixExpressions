#include "PostfixExpr.h"
#include "Tokenizer.h"
#include <stack>

#include <iostream>

double PostfixExpr::evaluate(std::string expr)
{
	Tokenizer exprTokenizer;
	std::stack<double> tokenStack;

	exprTokenizer.parse(expr);

	//Set Current Token Type
	Tokenizer::Tokens crtToken = exprTokenizer.crtTokenType();

	//Loop through all tokens
	while(crtToken != Tokenizer::Tokens::THEEND) {

		//Push onto Stack if Literal
		if (crtToken == Tokenizer::Tokens::LITERAL) {
			tokenStack.push(exprTokenizer.crtTokenValue().literalVal);
		}

		//Pop off Stack if Operator - Push new awnser to stack
		if (crtToken == Tokenizer::Tokens::OPERATOR) {
			double rhs = tokenStack.top(); tokenStack.pop();
			double lhs = tokenStack.top(); tokenStack.pop();

			tokenStack.push(evaluateOperator(exprTokenizer.crtTokenValue().opVal, lhs, rhs));
		}

		//Next token - Set crtTokenType
		exprTokenizer.nextToken();
		crtToken = exprTokenizer.crtTokenType();
	}

	return tokenStack.top();
}

double PostfixExpr::evaluateOperator(const Tokenizer::OperatorValue op, const double& lhs, const double& rhs) {
	switch (op) {
		case Tokenizer::OperatorValue::PLUS:  return lhs + rhs;
		case Tokenizer::OperatorValue::MINUS: return lhs - rhs;
		case Tokenizer::OperatorValue::STAR:  return lhs * rhs;
		case Tokenizer::OperatorValue::SLASH: return lhs / rhs;
	}
}