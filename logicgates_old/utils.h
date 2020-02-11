#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include "logic-gates.h"


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

typedef struct WBlock{
    ByteBlock byte[3];
    int length;
}WordBlock;

WordBlock EMPTY_WORD_BLOCK(void){
    int i;
    WordBlock w;
    for (i = 0; i < 3; i++){
        w.byte[i] = EMPTY_BYTE_BLOCK();
    }
    w.length = 3;
    return w;
}

WordBlock WORD_FROM_BYTES(ByteBlock A, ByteBlock B, ByteBlock C){
    WordBlock w;
    w.byte[0] = A;
    w.byte[1] = B;
    w.byte[2] = C;
    w.length = 3;
    return w;
}

ByteBlock BYTE_FROM_WORD(WordBlock w, int index){
    ByteBlock b = w.byte[index];
    return b;
}

void print_wordblock(WordBlock w){
    int i = 0;
    do
    {
        ByteBlock b = w.byte[i];
        int x = 0;
        do
        {
            printf("%d, ", b.block[x]);
            x++;
        } while (x < b.length);
        i++;
    } while (i < w.length);
    printf("\n");
}


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


typedef struct alu
{
    int cout;
    ByteBlock sum;

}ALUOUT;


typedef struct latch
{
    int q;
    int invq;
}Latch;


typedef struct bytelatch
{
    int q[8];
    int invq[8]; 
}ByteLatch;


ByteLatch EMPTY_BYTE_LATCH(void){
    int i;
    ByteLatch b;
    for (i = 0; i < 8; i++){
        b.q[i] = 0;
        b.invq[i] = 1;
    }
    return b;
}

ByteLatch BYTE_LATCH_FROM_BYTE_BLOCK(ByteBlock A){
    ByteLatch b;
    int i;
    for(i = 0; i < 8; i++){
        b.q[i] = A.block[i];
        b.invq[i] = NOT_gate(A.block[i]);
    }
    return b;
}


ByteBlock EMPTY_BYTE_BLOCK(void);
void print_byteblock(ByteBlock b);
WordBlock EMPTY_WORD_BLOCK(void);
WordBlock WORD_FROM_BYTES(ByteBlock A, ByteBlock B, ByteBlock C);
ByteBlock BYTE_FROM_WORD(WordBlock w, int index);
void print_wordblock(WordBlock w);
ByteLatch EMPTY_BYTE_LATCH(void);
ByteLatch BYTE_LATCH_FROM_BYTE_BLOCK(ByteBlock A);

#endif