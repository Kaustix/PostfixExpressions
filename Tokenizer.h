#ifndef __TOKENIZER_H
#define __TOKENIZER_H

#include <string>
#include <vector>

/// A simple lexical analyser 
/** Tokenizer parses string values and recognizes floating point
values and arithmetic operators.
*/
class Tokenizer {
public:
  /// identifiers for the kinds of tokens recognized
  enum class Tokens {
    LITERAL,  /**< the token is a value */
      OPERATOR,  /**< the token is an operator */
      UNKNOWN,  /**< the token is unrecognized */
      THEEND /**< no token, the end of the string has been reached */
      };

  /// identifiers for the different operators recognized
  enum class OperatorValue {
    STAR, /**< the operator is multiplication (*) */
      PLUS, /**< the operator is addition (+) */
      MINUS, /**< the operator is subtraction (-) */
      SLASH  /**< the operator is fractional division (/) */
      };

  /// type used for the value associated with a token
  union TokenValue {
    double literalVal;  /**< the value of a token if it is a literal */
    OperatorValue opVal; /**< the value of a token if it is an operator */
    
    /// constructors
    /** With these constructors, one can use TokenValue expressions
	directly as in TokenValue(OperatorValue::PLUS) 
	\param op the value for an operator token
    */
  TokenValue(OperatorValue op) : opVal(op) {};
    /** Constructor allowing the use of TokenValue expressions
	directly as in TokenValue(2.5)
	\param val the actual value of a token representing a literal
	or value
    */
  TokenValue(double val) : literalVal(val) {};
    /** By default, a TokenValue represents value 0.0 for a literal
	token */
  TokenValue(): TokenValue(0.0) {};
  };
		
  /// call to specify the string to be parsed
  /**
     \param str the string that will be parsed. After the call, the
     crtToken(Type/Value) functions are initialized to the first token
     from this string. Spaces can be used to separate tokens when
     needed. 
  */
  void parse(const std::string str);
  
  /// current token type, operator or literal
  /**
     \return a Tokens enum value representing the type of token parsed. A
     call to crtTokenType does not consume the token. The same token
     is still available until nextToken is called.
  */
  Tokens crtTokenType();
  
  /// the value associated with the current token
  /**
     \return a TokenValue union representing the value of the token. If
     the current token is a literal, then the literalVal field equals
     the value of the literal. If the token is an operator, then the
     opVal field identifies the operation.
  */
  TokenValue crtTokenValue();
  
  /// reads the next token from the string
  /**
     The next token from the string is parsed. Details about the new
     token are made available by the crtToken(Type/Value)
     functions. If there are no more tokens to be processed from the
     string, then crtTokenType returns the Tokens::THEEND value and
     crtTokenValue returns an undefined value.
  */
  void nextToken();

  std::vector<std::string> strList;
  int crtIndex;
};

#endif
