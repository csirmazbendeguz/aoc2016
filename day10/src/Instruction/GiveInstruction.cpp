#include "GiveInstruction.h"

void GiveInstruction::execute() {
  this->source->transferChips(this->lowTarget, this->highTarget);
}
