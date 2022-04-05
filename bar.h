// bar.h
// TO DO:  add header comment here.  Also add function header comments below.

#include <iostream>
#include <string>

#include "myrandom.h"  // used in autograder, do not remove
using namespace std;
//
// Bar
//
class Bar {
 private:
  // Private member variables for a Bar object
  // TO DO:  Define private member variables for this class
  // NOTE: You should not be allocating memory on the heap for this class.
  string Category;
  string Name;
  int Value;

 public:
  // default constructor:
  Bar() {
    Name = "";
    Value = 0;
    Category = "";
    // TO DO:  Write this constructor.
  }

  //
  // a second constructor:
  //
  // Parameter passed in constructor Bar object.
  //
  Bar(string name, int value, string category) {
    // TO DO:  Write this constructor.
    Value = value;
    Name = name;
    Category = category;
  }

  // destructor:
  virtual ~Bar() {
    this->Value = 0;
    this->Name = "";
    this->Category = "";
    // TO DO:  Write this destructor or leave empty if not needed.
  }

  // getName:
  string getName() {
    // TO DO:  Write this function.

    return this
        ->Name;  // TO DO:  update this, it is only here so code compiles.
  }

  // getValue:
  int getValue() {
    // TO DO:  Write this function.

    return this
        ->Value;  // TO DO:  update this, it is only here so code compiles.
  }

  // getCategory:
  string getCategory() {
    // TO DO:  Write this function.

    return this
        ->Category;  // TO DO:  update this, it is only here so code compiles.
  }

  // operators
  // TO DO:  Write these operators.  This allows you to compare two Bar
  // objects.  Comparison should be based on the Bar's value.  For example:
  bool operator<(const Bar &other) const {
    if (this->Value < other.Value) {
      return true;
    } else {
      return false;
    }
  }

  bool operator<=(const Bar &other) const {
    if (this->Value <= other.Value) {
      return true;
    } else {
      return false;
    }
  }

  bool operator>(const Bar &other) const {
    if (this->Value > other.Value) {
      return true;
    } else {
      return false;
    }
  }

  bool operator>=(const Bar &other) const {
    if (this->Value >= other.Value) {
      return true;
    } else {
      return false;
    }
  }
};