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

    int multiplied = o0->getValue() * o1->getValue() * o2->getValue();
    cout << multiplied << endl;
  }
  catch(const exception& e) {
    cerr << e.what() << endl;
  }

  return 0;
}
