#ifndef MULTIPLEXERS_H
#define MULTIPLEXERS_H

#include "logic-gates.h"

int multiplexer(int A, int B, int SL);
ByteBlock multiplexer_eight_bit(const ByteBlock A, const ByteBlock B, int SL);
ByteBlock four_input_multiplexer(ByteBlock A, ByteBlock B, ByteBlock C, ByteBlock D, int SL0, int SL1);

#endif