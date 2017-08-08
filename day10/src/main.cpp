#include <iostream>
#include "Factory.h"

using namespace std;

int main(int argc, char *argv[]) {
  // Read input.
  vector<string> lines;
  string line;
  while (getline(cin, line)) {
    lines.push_back(line);
  }

  try {
    // Start factory.
    Factory factory(&lines);

    // Part 2.
    Output* o0 = factory.getOutput(0);
    Output* o1 = factory.getOutput(1);
    Output* o2 = factory.getOutput(2);

    int multiplied = o0->value * o1->value * o2->value;
    cout << multiplied << endl;
  }
  catch(const exception& e) {
    cerr << e.what() << endl;
  }

  return 0;
}
