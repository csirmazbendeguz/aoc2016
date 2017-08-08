#ifndef __VALUEINSTRUCTION_H_INCLUDED__
#define __VALUEINSTRUCTION_H_INCLUDED__

#include "Instruction.h"
#include "../Reciever/Bot.h"

class ValueInstruction: public Instruction {
  public:
    int value;
    Bot* target;

    ValueInstruction(int value, Bot* target)
      : value(value), target(target)
    {}

    void execute() {
      this->target->addChip(this->value);
    }
};

#endif
