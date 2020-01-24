#ifndef LOGIC_GATES_H
#define LOGIC_GATES_H
#include <stdio.h>

typedef struct BBlock{
    int block[8];
    int length;
} ByteBlock;

ByteBlock EMPTY_BYTE_BLOCK(void){
    ByteBlock b;
    int i;
    for (i = 0; i < 8; i++){
        b.block[i] = 0;
    }
    b.length = 8;
    return b;
}

void print_byteblock(ByteBlock b){
    int i;
    for (i = 0; i < b.length; i++){
        printf("%d, ", b.block[i]);
    }
    printf("\n");
}

int buffer(int input_bool);
int NOT_gate(int input_bool);
int AND_gate(int A, int B);
int OR_gate(int A, int B);
int NAND_gate(int A, int B);
int NOR_gate(int A, int B);
int XOR_gate(int A, int B);

#endif