#ifndef __POSTFIXEXPR_H
#define __POSTFIXEXPR_H

#include <string>
#include "Tokenizer.h"


/// Responsibility: evaluating postfix expressions.
/**
Expressions consist only of literal fractional values and the four
arithmetic operators.
 */
class PostfixExpr {
 public:

  /// Evaluates a postfix expression
  /** Evaluates a postfix expression consisting only of positive
      values and the four operators + - / *.
      \param expr is the string containing the expression to be
      evaluated.
      \return the value of the expression
      \throws SyntaxError if the expression is mal formed.
      \throws LexicalError if the expression contains illegal characters.
   */
  double evaluate(std::string expr);
};


#endif
