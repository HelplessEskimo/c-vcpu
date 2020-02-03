#ifndef BINARY_H
#define BINARY_H
#include "logic-gates.h"
#include "adders.h"
#include "bitwise.h"
#include "multiplexer.h"
#include "utils.h"

#include "logic-gates.c"
#include "multiplexer.c"
#include "bitwise.c"
#include "adders.c"


int eight_bit_to_decimal(ByteBlock input);
ByteBlock decimal_to_binary(int a);

#endif