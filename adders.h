#ifndef ADDERS_H
#define ADDERS_H

#include "logic-gates.h"
#include "utils.h"

HalfAdder halfadder(int A, int B);
FullAdder fulladder(int A, int B, int CIN);
RippleAdder rippleadder(ByteBlock A, ByteBlock B, int CIN);

#endif