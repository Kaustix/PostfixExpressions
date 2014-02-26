#include "PostfixExpr.h"
#include "Tokenizer.h"
#include "exceptions.h"
#include <stack>

double PostfixExpr::evaluate(std::string expr)
{	
	if (expr.empty() || expr == "") throw SyntaxError("Syntax Error: Expression can't be NULL or Empty");
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
			if (tokenStack.size() < 2) throw SyntaxError("SyntaxError: Missing a literal");
			double rhs = tokenStack.top(); tokenStack.pop();
			double lhs = tokenStack.top(); tokenStack.pop();

			tokenStack.push(evaluateOperator(exprTokenizer.crtTokenValue().opVal, lhs, rhs));
		}

		//Next token - Set crtTokenType
		exprTokenizer.nextToken();
		crtToken = exprTokenizer.crtTokenType();
	}

	if (tokenStack.size() > 1) throw SyntaxError("SyntaxError: Missing an operand");
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