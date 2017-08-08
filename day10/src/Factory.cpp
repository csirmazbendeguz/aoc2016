#include "Factory.h"

Factory::Factory(vector<string>* lines) {
  regex valueInstruction("value ([[:digit:]]+) goes to bot ([[:digit:]]+)");
  smatch valueMatches;
  regex giveInstruction("bot ([[:digit:]]+) gives low to (bot|output) ([[:digit:]]+) and high to (bot|output) ([[:digit:]]+)");
  smatch giveMatches;

  for (string line : *lines) {
    if (regex_search(line, valueMatches, valueInstruction)) {
      int value = stoi(valueMatches[1].str());
      int botId = stoi(valueMatches[2].str());
      Bot* bot = this->getBot(botId);
      bot->addChip(value);
    } else if (regex_search(line, giveMatches, giveInstruction)) {
      int botId = stoi(giveMatches[1].str());
      string lowTargetType = giveMatches[2].str();
      int lowTargetId = stoi(giveMatches[3].str());
      string highTargetType = giveMatches[4].str();
      int highTargetId = stoi(giveMatches[5].str());

      Bot* source = getBot(botId);
      Reciever* lowTarget = (lowTargetType == "bot") ? (Reciever*) getBot(lowTargetId) : (Reciever*) getOutput(lowTargetId);
      Reciever* highTarget = (highTargetType == "bot") ? (Reciever*) getBot(highTargetId) : (Reciever*) getOutput(highTargetId);

      GiveInstruction* instruction = new GiveInstruction(source, lowTarget, highTarget);
      source->addInstruction(instruction);
    }
  }
}

Bot* Factory::getBot(int id) {
  if (this->bots.count(id) != 1) {
    Bot* bot = new Bot(id);
    this->bots[id] = bot;
  }
  return this->bots[id];
}

Output* Factory::getOutput(int id) {
  if (this->outputs.count(id) != 1) {
    Output* output = new Output(id);
    this->outputs[id] = output;
  }
  return this->outputs[id];
}
