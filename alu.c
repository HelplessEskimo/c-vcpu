#include "alu.h"

ALUOUT ALU(ByteBlock A, ByteBlock B, int s0, int s1, int s2, int s3, int s4){
    ALUOUT output;
    RippleAdder ra = rippleadder(A, bitwise_AND(bitwise_buffer(NOT_gate(s4)), bitwise_XOR(B, s3)),s2);
    ByteBlock anded_input = bitwise_AND(A, B);
    ByteBlock mux = four_input_multiplexer(ra.sum, anded_input, A, B, s0, s1);
    output.sum = mux;
    output.cout = ra.cout;
    return output;
}

int main(){
    WordBlock w = EMPTY_WORD_BLOCK();
    print_wordblock(w);
    printf("\n\n");
    ByteBlock A = EMPTY_BYTE_BLOCK();
    A.block[1] = 1;
    A.block[2] = 1;
    A.block[7] = 1; //01100001
    ByteBlock B = EMPTY_BYTE_BLOCK();
    B.block[5] = 1;
    B.block[4] = 1;
    B.block[7] = 1; //00001101
    print_byteblock(A);
    print_byteblock(B);
    ALUOUT ALUout = ALU(A, B, 0, 0, 1, 1, 0);

    print_byteblock(ALUout.sum);

    /*
    S4 S3 S2 S1 S0  Z
    0  0  0  0  0   ADD (A+B)
    0  0  0  0  1   BITWISE AND (A&B)
    0  0  0  1  0   INPUT A
    0  0  0  1  1   INPUT B
    0  1  1  0  0   SUBTRACT (A-B)
    1  0  1  0  0   INCREMENT (A+1)
    1  0  0  0  0   INPUT A
    0  0  1  0  0   ADD (A+B)+1
    0  1  0  0  0   SUBTRACT (A-B)-1
    */
    return 0;
}
