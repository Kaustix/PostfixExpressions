#include "Tokenizer.h"
#include "StringExtension.h"

#include <iostream>

void Tokenizer::parse(const std::string str) {
	crtIndex = 0;
	strList.push_back(str);
}

Tokenizer::Tokens Tokenizer::crtTokenType() {
	if (crtIndex >= strList.size()) {
		return Tokens::THEEND;
	}

	if (StringExtension::isDouble(strList[crtIndex])) {
		return Tokens::LITERAL;
	}

	if (StringExtension::isOperator(strList[crtIndex])) {
		return Tokens::OPERATOR;
	}

	return Tokens::UNKNOWN;
}

Tokenizer::TokenValue Tokenizer::crtTokenValue() {
	return OperatorValue::STAR;
}

void Tokenizer::nextToken() {
}