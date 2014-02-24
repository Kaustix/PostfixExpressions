#ifndef __EXCEPTIONS_H
#define __EXCEPTIONS_H

// cpsc 2720: exception classes used in Assignment 3

#include <stdexcept>

/// exception thrown in case a syntax error is discovered
/**
   \sa {LexicalError}
 */
class SyntaxError : public std::runtime_error {
 public:

  /// constructs an error object by passing a message
 explicit SyntaxError(const std::string & msg) : 
  runtime_error(msg) {};

  /// constructs an error object by passing a message
 explicit SyntaxError(const char * msg) :
  runtime_error(msg) {};
};


/// exception thrown in case a lexical error is discovered
/**
   Inherits from std::runtime_error.
   Construct an object by passing a string or cstring as message. Use
   the what function to access the message passed at construction.
 */
class LexicalError : public std::runtime_error {
 public:

  /// constructs an error object by passing a message
 explicit LexicalError(const std::string & msg) : 
  runtime_error(msg) {};

  /// constructs an error object by passing a message
 explicit LexicalError(const char * msg) :
  runtime_error(msg) {};
};

#endif
