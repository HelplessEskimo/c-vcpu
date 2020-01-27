#include "adders.h"
#include "logic-gates.c"

HalfAdder halfadder(int A, int B){
    HalfAdder output;

    output.cout = AND_gate(A, B);
    output.sum = XOR_gate(A, B);

    return output;
}

FullAdder fulladder(int A, int B, int CIN){
    FullAdder output;
    HalfAdder ha1;
    HalfAdder ha2;

    ha1 = halfadder(A, B);
    ha2 = halfadder(ha1.sum, CIN);

    output.cout = OR_gate(ha1.cout, ha2.cout);
    output.sum = ha2.sum;

    return output;

}

RippleAdder rippleadder(ByteBlock A, ByteBlock B, int CIN){
    ByteBlock out = EMPTY_BYTE_BLOCK();
    RippleAdder r;
    FullAdder f;  
    
    int cout = 0;
    int i = 7;
    
    do {
        if (i == 7){
            f = fulladder(A.block[i], B.block[i], CIN);
            cout = f.cout;
            out.block[i] = f.sum;
            //printf("%d\n", cout, f.sum);
        }
        else{
            f = fulladder(A.block[i], B.block[i], cout);
            cout = f.cout; 
            //printf("%d\n", cout);
            out.block[i] = f.sum;
        }
        i--;    
    }while(i >= 0);
    
    r.cout = f.cout;
    r.sum = out;

    return r;
}

int main(){
    unsigned x = 0;
    printf("x is %d\n", x);
    x--;
    printf("x is %d\n", x);
    ByteBlock A = EMPTY_BYTE_BLOCK();
    A.block[0] = 1;
    A.block[1] = 1;
    A.block[2] = 1;
    A.block[3] = 1;
    A.block[4] = 1;
    A.block[5] = 1;
    A.block[6] = 1;
    A.block[7] = 0;
    print_byteblock(A);
    ByteBlock B = EMPTY_BYTE_BLOCK();
    B.block[7] = 1;    
    print_byteblock(B);
    RippleAdder r = rippleadder(A, B, 0);
    print_byteblock(r.sum);
    printf("%d\n", r.cout);
}