#ifndef REG_H
#define REG_H

#include "d-flip-flop.h"
#include "utils.h"

#include "d-flip-flop.c"

ByteBlock common_register(ByteBlock D, int INV, int RST);
ByteBlock program_counter_register(ByteBlock D, int INV, int RST);
WordBlock ram_register(WordBlock D, int RST);

#endif