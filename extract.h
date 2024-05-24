#include <typeinfo>
#include <ctype.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "calc.h"

using namespace std;

class Extract {
  public:
    static int extractValues(const char* values[], int argCount);
};

int Extract::extractValues(const char* values[], int argCount){
  vector<int> numbers; 
  Calc calc;

  for (int i = 1; i < argCount; i++) {
    const char* currentValue = values[i];

    // if digit add to stack
    if (isdigit(*currentValue)) {
      int currentDigit = atoi(currentValue);
      numbers.push_back(currentDigit);
    }
    else {
      char currentOperator = *currentValue;
      if (numbers.size() == 2) {
        int result = calc.calculate(currentOperator, numbers.front(), numbers.back());
        numbers.clear(); // empty array
        numbers.insert(numbers.begin(), result);
      }
      else {
        const char* nextDigitRaw = values[i+1];
        int nextDigit = atoi(nextDigitRaw);
        numbers.push_back(nextDigit);

        int result = calc.calculate(currentOperator, numbers.front(), numbers.back());
        numbers.clear(); // empty array
        numbers.insert(numbers.begin(), result);

        i = i+1; // skip 1 step
      }
    }
    // for (int p = 0; p < numbers.size(); p++) {
    //   cout << "Current Stack" << endl;
    //   cout << "Digit " << p  << " = " << numbers[p] << endl;
    // }
  }
  return numbers[0];
}