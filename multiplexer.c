#include "multiplexer.h"

int multiplexer(int A, int B, int SL){
    int A_AND = AND_gate(A, NOT_gate(SL));
    int B_AND = AND_gate(B, SL);
    
    return OR_gate(A_AND, B_AND);
}

ByteBlock multiplexer_eight_bit(const ByteBlock A, const ByteBlock B, int SL){
    ByteBlock Z = EMPTY_BYTE_BLOCK();
    int bit;

    for (bit = 0; bit < 8; bit += 1){
        Z.block[bit] = multiplexer(A.block[bit], B.block[bit], SL);
    }
    
    return Z;
}

ByteBlock four_input_multiplexer(ByteBlock A, ByteBlock B, ByteBlock C, ByteBlock D, int SL0, int SL1){

    ByteBlock result = multiplexer_eight_bit(multiplexer_eight_bit(A, B, SL0), multiplexer_eight_bit(C, D, SL0), SL1);

    return result;
}