#ifndef MULTIPLEXERS_H
#define MULTIPLEXERS_H

#include "logic-gates.h"

int multiplexer(int A, int B, int SL);
ByteBlock multiplexer_eight_bit(const ByteBlock A, const ByteBlock B, int SL);

#endif