#include "multiplexer.h"
#include "logic-gates.c"

int multiplexer(int A, int B, int SL){
    int A_AND = AND_gate(A, NOT_gate(SL));
    int B_AND = AND_gate(B, SL);
    
    return OR_gate(A_AND, B_AND);
}

ByteBlock multiplexer_eight_bit(const ByteBlock A, const ByteBlock B, int SL){
    /*if (SL == 0){
        return A;
    }
    else if (SL == 1){
        return B;
    }
    else
    {
        printf("dumbass\n");
        return EMPTY_BYTE_BLOCK();
    }*/
    
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

int main(){
    ByteBlock A = EMPTY_BYTE_BLOCK();
    A.block[1] = 1;
    ByteBlock B = EMPTY_BYTE_BLOCK();
    B.block[4] = 1;
    int SL = 0;
    ByteBlock result = multiplexer_eight_bit(A, B, SL);
    print_byteblock(result);
    return 0;
}