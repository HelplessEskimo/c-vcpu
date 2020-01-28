#ifndef UTILS_H
#define UTILS_H
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


typedef struct WBlock{
    ByteBlock byte[8];
    int length;
}WordBlock;

WordBlock EMPTY_WORD_BLOCK(void){
    int i;
    WordBlock w;
    for (i = 0; i < 8; i++){
        w.byte[i] = EMPTY_BYTE_BLOCK();
    }
    w.length = 8;
    return w;
}

WordBlock WORD_FROM_BYTES(ByteBlock A, ByteBlock B, ByteBlock C, ByteBlock D, ByteBlock E, ByteBlock F, ByteBlock G, ByteBlock H){
    WordBlock w;
    w.byte[0] = A;
    w.byte[1] = B;
    w.byte[2] = C;
    w.byte[3] = D;
    w.byte[4] = E;
    w.byte[5] = F;
    w.byte[6] = G;
    w.byte[7] = H;
    w.length = 8;
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


ByteBlock EMPTY_BYTE_BLOCK(void);
void print_byteblock(ByteBlock b);
WordBlock EMPTY_WORD_BLOCK(void);
WordBlock WORD_FROM_BYTES(ByteBlock A, ByteBlock B, ByteBlock C, ByteBlock D, ByteBlock E, ByteBlock F, ByteBlock G, ByteBlock H);
ByteBlock BYTE_FROM_WORD(WordBlock w, int index);
void print_wordblock(WordBlock w);

#endif