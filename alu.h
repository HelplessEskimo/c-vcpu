#ifndef ALU_H
#define ALU_H
#include "logic-gates.h"
#include "adders.h"
#include "bitwise.h"
#include "multiplexer.h"

typedef struct alu
{
    int cout;
    ByteBlock sum;

}ALUOUT;


ALUOUT ALU(ByteBlock A, ByteBlock B, int s0, int s1, int s2, int s3, int s4);

#endif