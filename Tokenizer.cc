#include "Tokenizer.h"
#include "StringExtension.h"

#include <iostream>

void Tokenizer::parse(const std::string str) {
	crtIndex = 0;
	std::string crtLiteral;

	for(int i = 0; i < str.length(); i++) {
		std::string crtChar(1, str[i]);
    	if (StringExtension::isOperator(crtChar)) {
    		if (!crtLiteral.empty()) {
    			strList.push_back(crtLiteral);
    			crtLiteral.clear();
    		}
    		strList.push_back(crtChar);	
    	}
    	else {
    		if (crtChar != " ") {
    			crtLiteral += crtChar;
    		}
    		else {
    			if (!crtLiteral.empty()) {
    				strList.push_back(crtLiteral);
    				crtLiteral = "";
    			}
    		}
    	}
	}

	if (!crtLiteral.empty()) strList.push_back(crtLiteral);
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