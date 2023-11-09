// Assigment 3 by Keven Zepeda

#include "functions.h"

int main() {
  while (true) {
    int choice;
    cout << "Select your options:\n1) Inflix Expression\n2)Queues\n" << endl;
    cin >> choice;
    if (choice == 1) {
      string infixExpression;
      cout << "Enter an infix expression: ";
      cin >> infixExpression;

      if (isBalancedParentheses(infixExpression)) {
        string postfixExpression = infixToPostfix(infixExpression);
        cout << "Postfix expression: " << postfixExpression << endl;
      } else {
        cout << "The expression is invalid due to unbalanced parentheses."
             << endl;
      }
    } else if (choice == 2) {
      Queue myQueue;

      while (true) {
        int choice1;
        cout << "Queue Operations:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Check if empty\n";
        cout << "5. Get size\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice1;

        switch (choice1) {
        case 1:
          int element;
          cout << "Enter the element to enqueue: ";
          cin >> element;
          myQueue.enqueue(element);
          break;
        case 2:
          int dequeued;
          dequeued = myQueue.dequeue();
          if (dequeued == -1) {
            cout << "Queue is empty. Cannot dequeue." << endl;
          } else {
            cout << "Dequeued: " << dequeued << endl;
          }
          break;
        case 3:
          int front;
          front = myQueue.getFront();
          if (front == -1) {
            cout << "Queue is empty. Cannot retrieve front element." << endl;
          } else {
            cout << "Front: " << front << endl;
          }
          break;
        case 4:
          cout << "Queue is empty: " << myQueue.isEmpty() << endl;
          break;
        case 5:
          cout << "Size: " << myQueue.getSize() << endl;
          break;
        case 0:
          return 0;
        default:
          cout << "Invalid choice. Please try again." << endl;
        }
      }
    } else if (choice == 0) {
      break;
    } else {
      cout << "Try again" << endl;
    }
  }
  cout << "Thank you.";
  return 0;
}
