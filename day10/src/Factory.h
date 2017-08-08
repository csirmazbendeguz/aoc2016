#ifndef __FACTORY_H_INCLUDED__
#define __FACTORY_H_INCLUDED__

#include <map>
#include <regex>
#include "Reciever/Bot.h"
#include "Reciever/Output.h"
#include "Instruction/GiveInstruction.h"

using namespace std;

class Factory {
  public:
    Factory(vector<string>* lines);
    Bot* getBot(int id);
    Output* getOutput(int id);
  private:
    map<int, Bot*> bots;
    map<int, Output*> outputs;
};

#endif
