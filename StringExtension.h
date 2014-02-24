#ifndef __STRINGEXTENSION_H
#define __STRINGEXTENSION_H

#include <string>

class StringExtension {
public:
	static bool isDouble(const std::string& str) {
		char* input	= (char*)str.c_str();
		char* end;
		strtod(input, &end);
		if (*input == '\0') return false;
		return (end == input || *end != '\0');
  		//printf("fail - the following characters are not part of a double\n%s\n", end);
	}

	static bool isOperator(const std::string& str) {
		if (str == "+" || str == "-" || str == "/" || str == "*") {
			return true;
		}
		return false;
	}
};

#endif