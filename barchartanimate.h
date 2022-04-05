// barchartanimate.h
// TO DO:  Ayokunle Olugboyo
#include <unistd.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "barchart.h"
#include "myrandom.h"  // used in autograder, do not remove

using namespace std;

//
// BarChartAnimate
//
class BarChartAnimate {
 private:
  //
  // Private member variables for the abstraction.
  // This implementation uses a low-level C array, bars, to store a list of
  // BarCharts.  As a result, you must also keep track of the number of
  // elements stored (size) and the capacity of the array (capacity).
  // This IS dynamic array, so it must expand automatically, as needed.
  //
  BarChart *barcharts;  // pointer to a C-style array
  int size;
  int capacity;
  map<string, string> colorMap;
  vector<string> type;
  string title;
  string xlabel;
  string source;
  int color_index;

 public:
  // a parameterized constructor:
  // Like the ourvector, the barcharts C-array should be constructed here
  // with a capacity of 4.
  BarChartAnimate(string title, string xlabel, string source) {
    capacity = 4;
    size = 0;
    barcharts = new BarChart[capacity];
    this->source = source;
    this->title = title;
    this->xlabel = xlabel;
    color_index = 0;
  }

  //
  // destructor:
  //
  // Called automatically by C++ to free the memory associated
  // by BarChartAnimate.
  //
  virtual ~BarChartAnimate() {
    while (barcharts != nullptr) {
      delete[] barcharts;
      barcharts = nullptr;
    }
  }

  // addFrame:
  // adds a new BarChart to the BarChartAnimate object from the file stream.
  // if the barcharts has run out of space, double the capacity (see
  // ourvector.h for how to double the capacity).
  // See application.cpp and handout for pre and post conditions.
  void addFrame(ifstream &file) {
    int sum;
    string line, city, country, value, category;
    //
    getline(file, line);
    file >> sum;

    if (!file.good()) {
      return;
    }
    BarChart chart(sum);
    // get each line from the file
    for (int i = 0; i < sum; i++) {
      getline(file, line, ',');
      getline(file, city, ',');
      getline(file, country, ',');
      getline(file, value, ',');
      getline(file, category);
      // mapping each category to their respective colors
      if (colorMap.count(category) == 0) {
        colorMap[category] = COLORS[color_index];
        color_index++;
      }
      if (color_index == COLORS.size()) {
        color_index = 0;
      }
      chart.addBar(city, stoi(value), category);
      chart.setFrame(line);
    }
    // checking if the capacity is filled up to the max
    // if it has then it increases it
    if (size == capacity) {
      int cap = pow(capacity, 2);
      BarChart *b2 = new BarChart[cap];

      for (int i = 0; i < size; i++) {
        b2[i] = barcharts[i];
      }
      delete[] barcharts;
      capacity = cap;
      barcharts = b2;
      b2 = nullptr;
    }
    barcharts[size] = chart;
    size++;
  }

  // animate:
  // this function plays each frame stored in barcharts.  In order to see the
  // animation in the terminal, you must pause between each frame.  To do so,
  // type:  usleep(3 * microsecond);
  // Additionally, in order for each frame to print in the same spot in the
  // terminal (at the bottom), you will need to type: output << CLEARCONSOLE;
  // in between each frame.
  void animate(ostream &output, int top, int endIter) {
    unsigned int microsecond = 50000;

    if (endIter == -1) {
      endIter = size;
    }
    for (int i = 0; i < endIter; ++i) {
      usleep(3 * microsecond);

      output << CLEARCONSOLE;

      output << BLACK << title << endl;

      output << BLACK << source << endl;

      barcharts[i].graph(output, colorMap, top);

      output << BLACK << xlabel << endl;

      output << "Frame: " << barcharts[i].getFrame() << endl;
    }
  }

  //
  // Public member function.
  // Returns the size of the BarChartAnimate object.
  //
  int getSize() { return size; }

  //
  // Public member function.
  // Returns BarChart element in BarChartAnimate.
  // This gives public access to BarChart stored in the BarChartAnimate.
  // If i is out of bounds, throw an out_of_range error message:
  // "BarChartAnimate: i out of bounds"
  //
  BarChart &operator[](int i) {
    BarChart bc;

    if (i > size || i < 0) {
      throw out_of_range("BarChartAnimate: i out of bounds");
    }

    return barcharts[i];
  }
};
