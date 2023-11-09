#include <iostream>
#include <queue>
#include <stack>
#include <string>

#pragma once

using namespace std;

// queue
class Node {
public:
  int data;
  Node *next;

  Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
  Node *front;
  Node *rear;
  int size;

public:
  Queue() : front(nullptr), rear(nullptr), size(0) {}

  void enqueue(int element) {
    Node *newNode = new Node(element);
    if (isEmpty()) {
      front = newNode;
      rear = newNode;
    } else {
      rear->next = newNode;
      rear = newNode;
    }
    size++;
  }

  int dequeue() {
    if (isEmpty()) {
      // Handle the error in your way, e.g., print an error message or throw an
      // exception
      return -1;
    }
    Node *temp = front;
    int frontElement = front->data;
    front = front->next;
    delete temp;
    size--;
    return frontElement;
  }

  int getFront() {
    if (isEmpty()) {
      // Handle the error in your way, e.g., print an error message or throw an
      // exception
      return -1;
    }
    return front->data;
  }

  bool isEmpty() { return size == 0; }

  int getSize() { return size; }
};

// Infix to Postfix Conversion
bool isOperator(char c);
bool isOpeningBracket(char c);
bool isClosingBracket(char c);
bool isMatchingBracket(char open, char close);
bool isBalancedParentheses(const string &expression);
string infixToPostfix(const string &infixExpression);
