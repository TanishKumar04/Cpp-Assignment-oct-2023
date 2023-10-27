#include<iostream>

using namespace std;

void perform_operation(int *num1, int *num2, char op) {
   switch(op) {
       case '+':
           cout << "Sum: " << (*num1 + *num2) << endl;
           break;
       case '-':
           cout << "Difference: " << (*num1 - *num2) << endl;
           break;
       case '*':
           cout << "Product: " << (*num1 * *num2) << endl;
           break;
       case '/':
           if(*num2 == 0) {
               cout << "Error: Division by zero." << endl;
               break;
           }
           cout << "Quotient: " << (*num1 / *num2) << endl;
           break;
       default:
           cout << "Error: Invalid operator." << endl;
   }
}

int main() {
   int *num1, *num2;
   char op;

   cout << "Enter 2 integers: ";
   num1 = new int;
   num2 = new int;
   cin >> *num1 >> *num2;

   cout << "Enter an operator (+, -, *, /): ";
   cin >> op;

   perform_operation(num1, num2, op);

   delete num1;
   delete num2;

   return 0;
}