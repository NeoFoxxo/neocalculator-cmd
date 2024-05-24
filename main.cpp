#include <iostream>
#include "extract.h"
#include <ctype.h>

using namespace std;

int main(int argCount, const char* args[]){
  if (argCount < 4) {
    cout << "Please provide a valid equation" << endl;
    return 0;
  };

  try {
    int result = Extract::extractValues(args, argCount);
    cout << result << endl;
  }
  catch (...) {
    throw runtime_error("An error occurred");
  }

  return 0;
}