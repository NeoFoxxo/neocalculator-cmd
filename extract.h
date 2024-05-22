#include <typeinfo>
#include <ctype.h>
#include <cstdlib>
#include <iostream>

class Values {
  public:
    static int digits[10];
    static char operation;
};


class Extract {
  public:
    static Values extractValues(const char* values[], int argCount);
};


Values Extract::extractValues(const char* values[], int argCount){
  Values result; 
  for (int i = 1; i < argCount; i++) {
    auto currentValue = atof(values[i]);

    if (!isdigit(currentValue)) {
      result.operation = currentValue;
    } else {
      result.digits[i] = currentValue; 
    };
  }
  std::cout << result.digits << std::endl;

  return result;
}