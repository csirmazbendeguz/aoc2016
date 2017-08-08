#ifndef __OUTPUT_H_INCLUDED__
#define __OUTPUT_H_INCLUDED__

#include <exception>

#include "Reciever.h"

using namespace std;

class Output: Reciever {
  public:
    int id;
    int value = 0;

    Output(int id)
      : id(id)
    {}

    void addChip(int chip) {
      if (this->value) {
        throw logic_error("Can't add to output: already contains a value.");
      }
      this->value = chip;
    }
};

#endif
