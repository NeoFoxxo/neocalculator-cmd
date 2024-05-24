#include <iostream>

class Calc {
  public:
    int calculate(char currentOperator, int digit1, int digit2);
    int add(int digit1, int digit2);
    int multiply(int digit1, int digit2);
    int subtract(int digit1, int digit2);
    int divide(int digit1, int digit2);
};

int Calc::add(int digit1, int digit2){
  return digit1 + digit2;
}
int Calc::multiply(int digit1, int digit2){
  return digit1 * digit2;
}
int Calc::subtract(int digit1, int digit2){
  return digit1 - digit2;
}
int Calc::divide(int digit1, int digit2){
  if (digit2 == 0) {
    std::cout << "Cannot divide By 0" << std::endl;
    return 0;
  }
  return digit1 / digit2;
}

int Calc::calculate(char currentOperator, int digit1, int digit2){
  if (currentOperator == 'x') {
    return Calc::multiply(digit1, digit2);
  }
  if (currentOperator == '+') {
    return Calc::add(digit1, digit2);
  }
  if (currentOperator == '-') {
    return Calc::subtract(digit1, digit2);
  }
  else {
    return Calc::divide(digit1, digit2);
  }
}