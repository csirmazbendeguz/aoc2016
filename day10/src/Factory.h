#ifndef __FACTORY_H_INCLUDED__
#define __FACTORY_H_INCLUDED__

#include <map>
#include <regex>
#include <iostream>
#include "Reciever/Bot.h"
#include "Reciever/Output.h"
#include "Instruction/ValueInstruction.h"
#include "Instruction/GiveInstruction.h"

using namespace std;

class Factory {
  public:
    map<int, Bot*> bots;
    map<int, Output*> outputs;

    Factory(vector<string>* lines);
    Bot* getBot(int id);
    Output* getOutput(int id);
};

#endif
