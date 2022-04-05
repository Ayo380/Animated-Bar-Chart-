// Ayokunle Olugboyo
// tests.cpp
#include <iostream>

#include "barchartanimate.h"
using namespace std;

bool testBarDefaultConstructor() {
  Bar b;
  if (b.getName() != "") {
    cout << "testBarDefaultConstructor: getName failed" << endl;
    return false;
  } else if (b.getValue() != 0) {
    cout << "testBarDefaultConstructor: getValue failed" << endl;
    return false;
  } else if (b.getCategory() != "") {
    cout << "testBarDefaultConstructor: getCategory failed" << endl;
    return false;
  }
  cout << "testBarDefaultConstructor: all passed!" << endl;
  return true;
}

bool testBarParamConstructor() {
  Bar b("Chicago", 9234324, "US");
  if (b.getName() != "Chicago") {
    cout << "testBarParamConstructor: getName failed" << endl;
    return false;
  } else if (b.getValue() != 9234324) {
    cout << "testBarParamConstructor: getValue failed" << endl;
    return false;
  } else if (b.getCategory() != "US") {
    cout << "testBarParamConstructor: getCategory failed" << endl;
    return false;
  }
  cout << "testBarParamConstructor: all passed!" << endl;
  return true;
}
bool testBarBooleanOperator() {
  Bar b("Chicago", 1000, "US");
  Bar c("Miami", 2000, "US");
  if (b.operator<(c) != true) {
    cout << "testBarBooleanOperator: operator< failed" << endl;
    return false;
  } else if (b.operator<=(c) != true) {
    cout << "testBarBooleanOperator: operator<= failed" << endl;
    return false;
  } else if (b.operator>(c) != false) {
    cout << "testBarBooleanOperator: operator> failed" << endl;
    return false;
  } else if (b.operator>=(c) != false) {
    cout << "testBarBooleanOperator: operator>= failed" << endl;
    return false;
  }
  cout << "testBarBooleanOperator: all passed!" << endl;
  return true;
}

bool testDumpFunction() {
  BarChart testBar(3);
  map<string, string> testColor;
  testBar.addBar("Lagos", 235000, "Nigeria");
  testBar.addBar("Manchester", 550000, "England");
  testBar.addBar("Dublin", 100000, "Ireland");
  testBar.dump(cout);
  return true;
}

bool testprintBars() {
  BarChart testBar(5);

  testBar.addBar("Lagos", 210000, "Nigeria");
  testBar.addBar("Manchester", 4450000, "England");
  testBar.addBar("Berlin", 560000, "Germany");
  testBar.addBar("Dublin", 2000000, "Ireland");
  testBar.addBar("Accra", 40000000, "Ghana");

  // COLORS
  string CYAN("\033[1;36m");
  string GREEN("\033[1;32m");
  string GOLD("\033[1;33m");
  string RED("\033[1;31m");
  string PURPLE("\033[1;35m");
  string BLUE("\033[1;34m");
  string WHITE("\033[1;37m");
  string RESET("\033[0m");

  // map of colors
  map<string, string> colorMap;
  colorMap["Nigeria"] = GREEN;
  colorMap["England"] = PURPLE;
  colorMap["Germany"] = BLUE;
  colorMap["Ireland"] = CYAN;
  colorMap["Ghana"] = WHITE;

  testBar.graph(cout, colorMap, 5);
  testBar.clear();
  return true;
}
int main() {
  testBarDefaultConstructor();
  testBarParamConstructor();
  testBarBooleanOperator();
  testDumpFunction();
  testprintBars();
  return 0;
}
