#ifndef __INSTRUCTION_H_INCLUDED__
#define __INSTRUCTION_H_INCLUDED__

using namespace std;

class Instruction {
  public:
    virtual void execute() = 0;
};

#endif
