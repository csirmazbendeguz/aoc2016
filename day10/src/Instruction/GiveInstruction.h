#ifndef __GIVEINSTRUCTION_H_INCLUDED__
#define __GIVEINSTRUCTION_H_INCLUDED__

#include "../Reciever/Reciever.h"
#include "../Reciever/Bot.h"

using namespace std;

class Bot;
class Reciever;

class GiveInstruction {
  public:
    GiveInstruction(Bot* source, Reciever* lowTarget, Reciever* highTarget)
      : source(source), lowTarget(lowTarget), highTarget(highTarget)
    {}
    void execute();
  private:
    Bot* source;
    Reciever* lowTarget;
    Reciever* highTarget;
};

#endif
