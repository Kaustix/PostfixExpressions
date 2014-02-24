#include "Tokenizer.h"

void Tokenizer::parse(const std::string str) {
	crtIndex = 0;
	strList.push_back(str);
}

Tokenizer::Tokens Tokenizer::crtTokenType() {
	return Tokens::THEEND;
}

Tokenizer::TokenValue Tokenizer::crtTokenValue() {
	return OperatorValue::STAR;
}

void Tokenizer::nextToken() {
}