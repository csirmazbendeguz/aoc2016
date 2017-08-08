#ifndef __BOT_H_INCLUDED__
#define __BOT_H_INCLUDED__

#include <queue>
#include <iostream>
#include "Reciever.h"
#include "../Instruction/GiveInstruction.h"

using namespace std;

class GiveInstruction;

class Bot: public Reciever {
  public:
    Bot(int id): id(id) {};
    void addChip(int chip);
    void addInstruction(GiveInstruction* instruction);
    void transferChips(Reciever* lowTarget, Reciever* highTarget);
  private:
    int id;
    int low = 0, high = 0;
    queue<GiveInstruction*> instructions;

    void executeInstruction();
};

#endif
