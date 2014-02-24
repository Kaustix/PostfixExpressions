#include "Tokenizer.h"

void Tokenizer::parse(const std::string str) {
}

Tokenizer::Tokens Tokenizer::crtTokenType() {
	return Tokens::UNKNOWN;
}

Tokenizer::TokenValue Tokenizer::crtTokenValue() {
	return OperatorValue::STAR;
}

void Tokenizer::nextToken() {
}