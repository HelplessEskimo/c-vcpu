#ifndef BITWISE_H
#define BITWISE_H
#include "logic-gates.h"
#include "utils.h"

ByteBlock bitwise_XOR(ByteBlock A, int EN);
ByteBlock bitwise_AND(ByteBlock A, ByteBlock B);
ByteBlock bitwise_buffer(int A);

#endif