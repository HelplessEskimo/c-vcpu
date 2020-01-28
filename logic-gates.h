#ifndef LOGIC_GATES_H
#define LOGIC_GATES_H
#include "utils.h"

int buffer(int input_bool);
int NOT_gate(int input_bool);
int AND_gate(int A, int B);
int OR_gate(int A, int B);
int NAND_gate(int A, int B);
int NOR_gate(int A, int B);
int XOR_gate(int A, int B);

#endif