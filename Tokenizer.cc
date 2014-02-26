#include "Tokenizer.h"
#include "StringExtension.h"
#include "exceptions.h"

void Tokenizer::parse(const std::string str) {
	crtIndex = 0;
	std::string crtLiteral;

	for(int i = 0; i < str.length(); i++) {
		std::string crtChar(1, str[i]);	//convert char to string

		//Check if char is an Operator
    	if (StringExtension::isOperator(crtChar)) {
    		if (!crtLiteral.empty()) {
    			strList.push_back(crtLiteral);
    			crtLiteral.clear();
    		}
    		strList.push_back(crtChar);	
    	}

    	//Add literal to list or concat to crliteral
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

	//End of string push crtLiteral ifnot empty
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

	throw LexicalError("Unknown Token Type: " + strList[crtIndex]);
}

Tokenizer::TokenValue Tokenizer::crtTokenValue() {
	if (crtIndex < strList.size()) {
		switch (crtTokenType()) {
			case Tokens::LITERAL:
				return(TokenValue(atof(strList[crtIndex].c_str())));
			case Tokens::OPERATOR:
				if (strList[crtIndex] == "+") return TokenValue(OperatorValue::PLUS);
				if (strList[crtIndex] == "-") return TokenValue(OperatorValue::MINUS);
				if (strList[crtIndex] == "*") return TokenValue(OperatorValue::STAR);
				if (strList[crtIndex] == "/") return TokenValue(OperatorValue::SLASH);
		}
	}
}

void Tokenizer::nextToken() {
	++crtIndex;
}