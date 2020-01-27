#include "logic-gates.c"
#include "bitwise.h"

ByteBlock bitwise_XOR(ByteBlock A, int EN){
    int i = 0;
    ByteBlock out = EMPTY_BYTE_BLOCK();

    do
    {
        out.block[i] = XOR_gate(A.block[i], EN);
        i++;
    } while (i <= 7);

    return out;
}

ByteBlock bitwise_AND(ByteBlock A, ByteBlock B){
    int i = 0;
    ByteBlock out = EMPTY_BYTE_BLOCK();

    do
    {
        out.block[i] = AND_gate(A.block[i], B.block[i]);
        i++;
    } while (i <= 7);

    return out;
}

ByteBlock bitwise_buffer(int A){
    int i = 0;
    ByteBlock out = EMPTY_BYTE_BLOCK();

    do
    {
        out.block[i] = A;
        i++;
    } while (i <= 7);

    return out;
}
