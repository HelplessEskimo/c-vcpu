#ifndef ADDERS_H
#define ADDERS_H

#include "logic-gates.h"

typedef struct halfadder{
   int sum;
   int cout;

} HalfAdder;

typedef struct fulladder{
    int sum;
    int cout;

}FullAdder;

typedef struct rippleadder{
    ByteBlock sum;
    int cout;

}RippleAdder;


HalfAdder halfadder(int A, int B);
FullAdder fulladder(int A, int B, int CIN);
RippleAdder rippleadder(ByteBlock A, ByteBlock B, int CIN);

#endif