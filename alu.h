#ifndef ALU_H
#define ALU_H
#include "logic-gates.h"
#include "adders.h"
#include "bitwise.h"
#include "multiplexer.h"
#include "utils.h"

#include "logic-gates.c"
#include "multiplexer.c"
#include "bitwise.c"
#include "adders.c"


ALUOUT ALU(ByteBlock A, ByteBlock B, int s0, int s1, int s2, int s3, int s4);

#endif