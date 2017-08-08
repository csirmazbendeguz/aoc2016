#include "Bot.h"

void Bot::addChip(int chip) {
  if (this->low && this->high) {
    throw logic_error("Can't add chip: the hands are full.");
  }

  if (!this->low) {
    this->low = chip;
  } else if (chip < this->low) {
    this->high = this->low;
    this->low = chip;
  } else if (chip > this->low) {
    this->high = chip;
  }

  if (this->low == 17 && this->high == 61) {
    cout << this->id << endl;
  }

  this->executeInstruction();
}

void Bot::executeInstruction() {
  if (this->low && this->high) {
    GiveInstruction* instruction = this->instructions.front();
    if (instruction) {
      this->instructions.pop();
      instruction->execute();
      delete instruction;
    }
  }
}

void Bot::addInstruction(GiveInstruction* instruction) {
  this->instructions.push(instruction);
  this->executeInstruction();
}

void Bot::transferChips(Reciever* lowTarget, Reciever* highTarget) {
  if (!this->low) {
    throw logic_error("Can't transfer: low hand is empty.");
  }
  if (!this->high) {
    throw logic_error("Can't transfer: high hand is empty.");
  }
  lowTarget->addChip(this->low);
  this->low = 0;
  highTarget->addChip(this->high);
  this->high = 0;
}
