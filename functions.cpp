#include "functions.h"

// Infix to Postfix Conversion
bool isOperator(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

bool isOpeningBracket(char c) { return (c == '{' || c == '(' || c == '['); }

bool isClosingBracket(char c) { return (c == '}' || c == ')' || c == ']'); }

bool isMatchingBracket(char open, char close) {
  return ((open == '{' && close == '}') || (open == '(' && close == ')') ||
          (open == '[' && close == ']'));
}

bool isBalancedParentheses(const string &expression) {
  stack<char> stack;
  for (char c : expression) {
    if (isOpeningBracket(c)) {
      stack.push(c);
    } else if (isClosingBracket(c)) {
      if (stack.empty() || !isMatchingBracket(stack.top(), c)) {
        return false;
      }
      stack.pop();
    }
  }
  return stack.empty();
}

string infixToPostfix(const string &infixExpression) {
  string postfix;
  stack<char> operators;

  for (char c : infixExpression) {
    if (isalnum(c)) {
      postfix += c;
    } else if (isOperator(c)) {
      while (!operators.empty() && operators.top() != '(' &&
             operators.top() != '{' && operators.top() != '[' &&
             (c == '+' || c == '-' ||
              (c == '*' || c == '/' || c == '%') &&
                  (operators.top() == '*' || operators.top() == '/' ||
                   operators.top() == '%'))) {
        postfix += operators.top();
        operators.pop();
      }
      operators.push(c);
    } else if (isOpeningBracket(c)) {
      operators.push(c);
    } else if (isClosingBracket(c)) {
      while (!operators.empty() && operators.top() != '(' &&
             operators.top() != '{' && operators.top() != '[') {
        postfix += operators.top();
        operators.pop();
      }
      operators.pop(); // Remove the matching opening bracket
    }
  }

  while (!operators.empty()) {
    postfix += operators.top();
    operators.pop();
  }

  return postfix;
}
