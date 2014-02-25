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
	if (crtIndex < strList.size()) {
		Tokenizer::TokenValue tValue;
		switch (crtTokenType()) {
			case Tokens::LITERAL:
				tValue.literalVal = atof(strList[crtIndex].c_str());
				return tValue;
			case Tokens::OPERATOR:
				if (strList[crtIndex] == "+") tValue.opVal = OperatorValue::PLUS;
				if (strList[crtIndex] == "-") tValue.opVal = OperatorValue::MINUS;
				if (strList[crtIndex] == "*") tValue.opVal = OperatorValue::STAR;
				if (strList[crtIndex] == "/") tValue.opVal = OperatorValue::SLASH;
				return tValue;
		}
	}
}

void Tokenizer::nextToken() {
	++crtIndex;
}